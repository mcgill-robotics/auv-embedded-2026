#ifdef POWER_H
#include "power_main.h"
#include <Arduino.h>
#include "ThrusterControl.h"
#include "adc_sensors.h"
#include "TMP36.h"

#include <micro_ros_arduino.h>
#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>

#include <std_msgs/msg/int16_multi_array.h>
#include <std_msgs/msg/float32.h>
#include <std_msgs/msg/float32_multi_array.h>
#include <std_msgs/msg/string.h>   // state topic

#define LED_PIN 13
#define ENABLE_VOLTAGE_SENSE true
#define ENABLE_CURRENT_SENSE true

// Safer propulsion command timeout (ms) – tune >= your nominal command period
#define PROPULSION_TIMEOUT_MS 2000

ADCSensors adcSensors;
TMP36 temperatureSensor(23, 3.3);

bool micro_ros_init_successful;

rcl_subscription_t propulsion_microseconds_subscriber;
std_msgs__msg__Int16MultiArray propulsion_microseconds_msg;

rcl_publisher_t power_batteries_voltage_publisher;
std_msgs__msg__Float32MultiArray power_batteries_voltage_msg;

rcl_publisher_t power_thrusters_current_publisher;
std_msgs__msg__Float32MultiArray power_thrusters_current_msg;

rcl_publisher_t power_board_temperature_publisher;
std_msgs__msg__Float32 power_board_temperature_msg;

rcl_publisher_t power_teensy_temperature_publisher;
std_msgs__msg__Float32 power_teensy_temperature_msg;

// state echo publisher
rcl_publisher_t power_state_publisher;
std_msgs__msg__String power_state_msg;

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
rcl_timer_t timer;

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

#define EXECUTE_EVERY_N_MS(MS, X)  do { \
  static volatile int64_t init = -1; \
  if (init == -1) { init = uxr_millis();} \
  if (uxr_millis() - init > MS) { X; init = uxr_millis();} \
} while (0)

void error_loop() {
  int error = 0;
  while (error < 10) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
    error++;
  }
  digitalWrite(LED_PIN, HIGH);
}

enum states {
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

// Watchdog book-keeping
uint32_t last_propulsion_cmd_ms = 0;
bool propulsion_in_failsafe = false;

// helper to publish current state as string
void publish_state()
{
  const char * text = "UNKNOWN";
  switch (state) {
    case WAITING_AGENT:      text = "WAITING_AGENT";      break;
    case AGENT_AVAILABLE:    text = "AGENT_AVAILABLE";    break;
    case AGENT_CONNECTED:    text = "AGENT_CONNECTED";    break;
    case AGENT_DISCONNECTED: text = "AGENT_DISCONNECTED"; break;
    default:                 text = "UNKNOWN";            break;
  }

  static const size_t BUF_CAP = 32;
  static bool initialized = false;
  if (!initialized) {
    power_state_msg.data.data = (char*) malloc(BUF_CAP);
    power_state_msg.data.capacity = BUF_CAP;
    power_state_msg.data.size = 0;
    initialized = true;
  }

  size_t len = strnlen(text, BUF_CAP - 1);
  memcpy(power_state_msg.data.data, text, len);
  power_state_msg.data.data[len] = '\0';
  power_state_msg.data.size = len;

  RCSOFTCHECK(rcl_publish(&power_state_publisher, &power_state_msg, NULL));
}

void propulsion_microseconds_callback(const void * msgin) {
  const std_msgs__msg__Int16MultiArray * msg =
      (const std_msgs__msg__Int16MultiArray *)msgin;

  for (int i = 0; i < 8; i++) {
    microseconds[i] = msg->data.data[i];
  }

  // New command: refresh watchdog and exit failsafe
  last_propulsion_cmd_ms = millis();
  propulsion_in_failsafe = false;
}

void timer_callback(rcl_timer_t * timer, int64_t last_call_time) {
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    RCSOFTCHECK(rcl_publish(&power_batteries_voltage_publisher, &power_batteries_voltage_msg, NULL));
    RCSOFTCHECK(rcl_publish(&power_thrusters_current_publisher, &power_thrusters_current_msg, NULL));
    RCSOFTCHECK(rcl_publish(&power_board_temperature_publisher, &power_board_temperature_msg, NULL));
    RCSOFTCHECK(rcl_publish(&power_teensy_temperature_publisher, &power_teensy_temperature_msg, NULL));
  }
}

bool create_entities() {
  allocator = rcl_get_default_allocator();
  // create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  // create node
  RCCHECK(rclc_node_init_default(&node, "power_node", "", &support));

  RCCHECK(rclc_subscription_init_default(
      &propulsion_microseconds_subscriber,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int16MultiArray),
      "/propulsion/microseconds"));

  // publishers
  RCCHECK(rclc_publisher_init_default(
      &power_batteries_voltage_publisher,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32MultiArray),
      "/power/batteries/voltage"));

  RCCHECK(rclc_publisher_init_default(
      &power_thrusters_current_publisher,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32MultiArray),
      "/power/thrusters/current"));

  RCCHECK(rclc_publisher_init_default(
      &power_board_temperature_publisher,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
      "/power/board/temperature"));

  RCCHECK(rclc_publisher_init_default(
      &power_teensy_temperature_publisher,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
      "/power/teensy/temperature"));

  // state publisher
  RCCHECK(rclc_publisher_init_default(
      &power_state_publisher,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
      "/power/state"));

  // timer
  const unsigned int timer_timeout = 1000;
  RCCHECK(rclc_timer_init_default(
      &timer,
      &support,
      RCL_MS_TO_NS(timer_timeout),
      timer_callback));

  // executor
  executor = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor, &support.context, 100, &allocator));
  RCCHECK(rclc_executor_add_timer(&executor, &timer));
  RCCHECK(rclc_executor_add_subscription(&executor, &propulsion_microseconds_subscriber,
                                         &propulsion_microseconds_msg,
                                         &propulsion_microseconds_callback,
                                         ON_NEW_DATA));

  // Reset microseconds array to 1500 when ROS entities are created/reconnected
  for (int i = 0; i < 8; i++) {
    microseconds[i] = 1500;
  }

  // reset watchdog
  last_propulsion_cmd_ms = millis();
  propulsion_in_failsafe = false;

  return true;
}

void disconnectUSB() {
  USB1_USBCMD = 0;
}

void connectUSB() {
  USB1_USBCMD = 1;
}

void destroy_entities() {
  disconnectUSB();
  delay(25);

  // Reset microseconds array to 1500 before destroying entities for safety
  for (int i = 0; i < 8; i++) {
    microseconds[i] = 1500;
  }

  updateThrusters(offCommand);

  rmw_context_t * rmw_context = rcl_context_get_rmw_context(&support.context);
  (void) rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_publisher_fini(&power_batteries_voltage_publisher, &node);
  rcl_publisher_fini(&power_thrusters_current_publisher, &node);
  rcl_publisher_fini(&power_board_temperature_publisher, &node);
  rcl_publisher_fini(&power_teensy_temperature_publisher, &node);
  rcl_publisher_fini(&power_state_publisher, &node);
  rcl_subscription_fini(&propulsion_microseconds_subscriber, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor);
  rcl_node_fini(&node);
  rclc_support_fini(&support);

  delay(25);
  connectUSB();
}

void senseData() {
  power_board_temperature_msg.data = temperatureSensor.readTemperature();
  power_teensy_temperature_msg.data = tempmonGetTemp();

  float* current_data = adcSensors.senseCurrent();
  for (size_t i = 0; i < 8; i++) {
    power_thrusters_current_msg.data.data[i] = current_data[i];
  }

  float* voltage_data = adcSensors.senseVoltage();
  for (size_t i = 0; i < 2; i++) {
    power_batteries_voltage_msg.data.data[i] = voltage_data[i];
  }
}

void power_setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  initThrusters();
  adcSensors.begin(ENABLE_VOLTAGE_SENSE, ENABLE_CURRENT_SENSE, &Wire1);
  temperatureSensor.begin();

  // Configure serial transport
  Serial.begin(115200);
  set_microros_transports();

  delay(2000);

  // allocates correct message sizes and initializes to 0, required or crashes
  propulsion_microseconds_msg.data.size = 8;
  propulsion_microseconds_msg.data.capacity = 8;
  propulsion_microseconds_msg.data.data = (int16_t*)malloc(propulsion_microseconds_msg.data.capacity * sizeof(int16_t));
  for (int i = 0; i < 8; i++) {
    propulsion_microseconds_msg.data.data[i] = 0;
  }

  power_batteries_voltage_msg.data.size = 2;
  power_batteries_voltage_msg.data.capacity = 2;
  power_batteries_voltage_msg.data.data = (float*)malloc(power_batteries_voltage_msg.data.capacity * sizeof(float));
  for (int i = 0; i < 2; i++) {
    power_batteries_voltage_msg.data.data[i] = 0.0;
  }

  power_thrusters_current_msg.data.size = 8;
  power_thrusters_current_msg.data.capacity = 8;
  power_thrusters_current_msg.data.data = (float*)malloc(power_thrusters_current_msg.data.capacity * sizeof(float));
  for (int i = 0; i < 8; i++) {
    power_thrusters_current_msg.data.data[i] = 0.0;
  }

  power_board_temperature_msg.data = 0.0;
  power_teensy_temperature_msg.data = 0.0;

  // allocates thrusters to 1500 in case of reset
  for (int i = 0; i < 8; i++) {
    propulsion_microseconds_msg.data.data[i] = 1500;
  }

  // Initialize the actual microseconds array (used by updateThrusters) to 1500 on reset
  for (int i = 0; i < 8; i++) {
    microseconds[i] = 1500;
  }

  for (int i = 0; i < 2; i++) {
    power_batteries_voltage_msg.data.data[i] = -2.0;
  }

  for (int i = 0; i < 8; i++) {
    power_thrusters_current_msg.data.data[i] = -2.0;
  }

  power_board_temperature_msg.data = -2.0;
  power_teensy_temperature_msg.data = -2.0;

  // first state
  state = WAITING_AGENT;
  publish_state();

  // watchdog initial values
  last_propulsion_cmd_ms = millis();
  propulsion_in_failsafe = false;
}

void power_loop() {
  senseData();

  // Non-blocking propulsion command timeout / kill
  if (state == AGENT_CONNECTED) {
    uint32_t now = millis();
    uint32_t dt  = now - last_propulsion_cmd_ms;

    if (dt > PROPULSION_TIMEOUT_MS && !propulsion_in_failsafe) {
      // Enter failsafe once: set all channels to 1500 us
      for (int i = 0; i < 8; i++) {
        microseconds[i] = 1500;
      }
      propulsion_in_failsafe = true;
    }
    // If dt <= timeout, or already in failsafe, leave microseconds[] to callback logic
  } else {
    // Not connected to agent: force safe and mark as failsafe
    for (int i = 0; i < 8; i++) {
      microseconds[i] = 1500;
    }
    propulsion_in_failsafe = true;
  }

  updateThrusters(microseconds);

  switch (state) {
    case WAITING_AGENT:
      EXECUTE_EVERY_N_MS(500,
        state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ?
                  AGENT_AVAILABLE : WAITING_AGENT;
        publish_state();
      );
      break;

    case AGENT_AVAILABLE:
      state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
      publish_state();
      if (state == WAITING_AGENT) {
        destroy_entities();
      };
      break;

    case AGENT_CONNECTED:
      EXECUTE_EVERY_N_MS(200,
        state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ?
                  AGENT_CONNECTED : AGENT_DISCONNECTED;
        publish_state();
      );
      if (state == AGENT_CONNECTED) {
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
      }
      break;

    case AGENT_DISCONNECTED:
      destroy_entities();
      state = WAITING_AGENT;
      publish_state();
      break;

    default:
      break;
  }

  if (state == AGENT_CONNECTED) {
    digitalWrite(LED_PIN, 1);
  } else {
    digitalWrite(LED_PIN, 0);
  }
}

#endif
