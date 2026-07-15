#ifdef ACTUATOR_H

#include "actuator_main.h"

// Basic libraries
#include <Arduino.h>
#include <Servo.h>

// MicroROS libraries
#include <micro_ros_arduino.h>
#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>

// std msg type libraries
#include <std_msgs/msg/u_int8.h>

// Logging publisher
#include <std_msgs/msg/string.h>
#include <rosidl_runtime_c/string_functions.h>
// Error checking macros

// Define torpedo Positions
#define OPEN_ONE 1065
#define CLOSED 1450
#define OPEN_BOTH 1900

// Define grabber Positions
#define GRABBER_CLOSED 900
#define GRABBER_OPEN 2100

// Define pins on Teensy
// J1 = 8, J2 = 9, J3 = 10, J4 = 11, J5 = 12
#define LED_PIN 13
#define TORPEDO_PIN 10
#define GRABBER_PIN 11

void error_loop() {
  int error = 0;
  while (error < 10) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
    error++;
  }
  digitalWrite(LED_PIN, HIGH);
}

// Error checking macros
#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop(); return false;}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}

// Macro for non-blocking timing in the state machine
#define EXECUTE_EVERY_N_MS(MS, X)      \
  do                                   \
  {                                    \
    static volatile int64_t init = -1; \
    if (init == -1)                    \
    {                                  \
      init = uxr_millis();             \
    }                                  \
    if (uxr_millis() - init > MS)      \
    {                                  \
      X;                               \
      init = uxr_millis();             \
    }                                  \
  } while (0)

// Declare Servo objects
Servo torpedoServo;
Servo grabberServo;

// Declare microROS variables
rcl_subscription_t torpedo_subscriber;
rcl_subscription_t grabber_subscriber;
std_msgs__msg__UInt8 torpedo_msg;
std_msgs__msg__UInt8 grabber_msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;
// log publisher
rcl_publisher_t log_publisher;
std_msgs__msg__String log_msg;

// Torpedo position commands
enum torpedo_positions
{
  closed = 0,
  shoot_one = 1,
  shoot_two = 2
} torpedo_command;

// Grabber position commands
enum grabber_positions
{
  grabber_open = 0,
  grabber_closed = 1
} grabber_command;

// Target positions for non-blocking servo movement
int target_torpedo_us = CLOSED;
int target_grabber_us = GRABBER_OPEN;

// Forward declarations
bool create_entities();
void destroy_entities();

// Define states for the connection state machine
enum states
{
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

// Functions to manually redeclare USB to deal with disconnect/reconnect
void disconnectUSB()
{
  USB1_USBCMD = 0;
}
void connectUSB()
{
  USB1_USBCMD = 1;
}

// Function to convert between ROS2 grabber positions and actual angles
int grabberMsgToAngle(uint8_t grabberPositionMsg) {

  // ((grabberMaxAngle - grabberMinAngle)/(maxMsg - minMsg))(inputMsg) + grabberMinAngle;
  int grabberAngle = (int)(float)(((GRABBER_OPEN - GRABBER_CLOSED)/(255.0f))*(grabberPositionMsg) + GRABBER_CLOSED);
  
  return grabberAngle;
}

// Non-blocking servo update called inside actuator_loop()
void updateServos()
{
  static int64_t last_step_time = 0;
  int64_t now = uxr_millis();
  if (now - last_step_time < 2)
  {
    return;
  }
  last_step_time = now;

  int cur_torpedo = torpedoServo.readMicroseconds();
  if (cur_torpedo != target_torpedo_us)
  {
    int step = (target_torpedo_us > cur_torpedo) ? 50 : -50;
    if (abs(target_torpedo_us - cur_torpedo) <= abs(step))
    {
      torpedoServo.writeMicroseconds(target_torpedo_us);
    }
    else
    {
      torpedoServo.writeMicroseconds(cur_torpedo + step);
    }
  }

  int cur_grabber = grabberServo.readMicroseconds();
  if (cur_grabber != target_grabber_us)
  {
    int step = (target_grabber_us > cur_grabber) ? 20 : -20;
    if (abs(target_grabber_us - cur_grabber) <= abs(step))
    {
      grabberServo.writeMicroseconds(target_grabber_us);
    }
    else
    {
      grabberServo.writeMicroseconds(cur_grabber + step);
    }
  }
}

// Function to parse torpedo msg and set target position accordingly
void torpedo_callback(const void *msgin)
{
  const std_msgs__msg__UInt8 *msg = (const std_msgs__msg__UInt8 *)msgin;
  torpedo_command = (torpedo_positions)msg->data;

  switch (torpedo_command)
  {
  case closed:
    target_torpedo_us = CLOSED;
    {
      char buf[128];
      int cur = torpedoServo.readMicroseconds();
      snprintf(buf, sizeof(buf), "TORPEDO callback cur:%d target:%d", cur, target_torpedo_us);
      rosidl_runtime_c__String__assign(&log_msg.data, buf);
      RCSOFTCHECK(rcl_publish(&log_publisher, &log_msg, NULL));
    }
    break;
  case shoot_one:
    target_torpedo_us = OPEN_ONE;
    {
      char buf[128];
      int cur = torpedoServo.readMicroseconds();
      snprintf(buf, sizeof(buf), "TORPEDO callback cur:%d target:%d", cur, target_torpedo_us);
      rosidl_runtime_c__String__assign(&log_msg.data, buf);
      RCSOFTCHECK(rcl_publish(&log_publisher, &log_msg, NULL));
    }
    break;
  case shoot_two:
    target_torpedo_us = OPEN_BOTH;
    {
      char buf[128];
      int cur = torpedoServo.readMicroseconds();
      snprintf(buf, sizeof(buf), "TORPEDO callback cur:%d target:%d", cur, target_torpedo_us);
      rosidl_runtime_c__String__assign(&log_msg.data, buf);
      RCSOFTCHECK(rcl_publish(&log_publisher, &log_msg, NULL));
    }
    break;
  default:
    break;
  }
}

// Function to parse grabber msg and set target position accordingly
void grabber_callback(const void *msgin)
{
  const std_msgs__msg__UInt8 *msg = (const std_msgs__msg__UInt8 *)msgin;
  uint8_t in = msg->data;
  int target = grabberMsgToAngle(in);
  target_grabber_us = target;
  // publish log
  char buf[128];
  int cur = grabberServo.readMicroseconds();
  snprintf(buf, sizeof(buf), "GRABBER callback cur:%d target:%d", cur, target_grabber_us);
  rosidl_runtime_c__String__assign(&log_msg.data, buf);
  RCSOFTCHECK(rcl_publish(&log_publisher, &log_msg, NULL));
}

// Setup function
void actuator_setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  // Set transport to serial
  Serial.begin(115200);
  set_microros_transports();
  // delay(500);

  // Attach and initialize grabber servo
  grabberServo.attach(GRABBER_PIN);
  // delay(100);
  grabberServo.writeMicroseconds(GRABBER_OPEN);
  target_grabber_us = GRABBER_OPEN;
  // delay(500);

  // Attach and initialize torpedo servo
  torpedoServo.attach(TORPEDO_PIN);
  // delay(100);
  torpedoServo.writeMicroseconds(CLOSED);
  target_torpedo_us = CLOSED;
  // delay(500);

  // Set initial msgs
  torpedo_msg.data = closed;
  grabber_msg.data = grabber_open;

  // Initialize state machine
  state = WAITING_AGENT;
}

// Create all entities required for ros
bool create_entities()
{
  allocator = rcl_get_default_allocator();

  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  node = rcl_get_zero_initialized_node();
  RCCHECK(rclc_node_init_default(&node, "actuator_node", "", &support));

  // Torpedo subscriber
  torpedo_subscriber = rcl_get_zero_initialized_subscription();
  RCCHECK(rclc_subscription_init_default(
      &torpedo_subscriber,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, UInt8),
      "/actuators/torpedo"));

  // Grabber subscriber
  grabber_subscriber = rcl_get_zero_initialized_subscription();
  RCCHECK(rclc_subscription_init_default(
      &grabber_subscriber,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, UInt8),
      "/actuators/grabber"));

  // Zero-initialize executor and use 10 handles for proper memory allocation
  executor = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor, &support.context, 10, &allocator));

  RCCHECK(rclc_executor_add_subscription(&executor, &torpedo_subscriber, &torpedo_msg, &torpedo_callback, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_subscription(&executor, &grabber_subscriber, &grabber_msg, &grabber_callback, ON_NEW_DATA));

  // Initialize log publisher
  std_msgs__msg__String__init(&log_msg);
  RCCHECK(rclc_publisher_init_default(&log_publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String), "/actuators/log"));

  return true;
}

// Destroy all entities required for ros
void destroy_entities()
{
  rmw_context_t *rmw_context = rcl_context_get_rmw_context(&support.context);
  (void)rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  // Clean up executor first while USB is active before destroying subscriptions/node
  rclc_executor_fini(&executor);
  rcl_subscription_fini(&torpedo_subscriber, &node);
  rcl_subscription_fini(&grabber_subscriber, &node);
  rcl_publisher_fini(&log_publisher, &node);
  std_msgs__msg__String__fini(&log_msg);
  rcl_node_fini(&node);
  rclc_support_fini(&support);

  // Toggle USB after entities are fully freed
  // disconnectUSB();
  // delay(100);
  // connectUSB();
  // delay(100);
}

// Main function; state machine to handle ros connection state
void actuator_loop()
{
  switch (state)
  {
  case WAITING_AGENT:
    EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
    break;

  case AGENT_AVAILABLE:
    state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
    if (state == WAITING_AGENT)
    {
      destroy_entities();
    }
    break;

  case AGENT_CONNECTED:
    EXECUTE_EVERY_N_MS(200, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
    if (state == AGENT_CONNECTED)
    {
      rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
      updateServos();
    }
    break;

  case AGENT_DISCONNECTED:
    destroy_entities();
    state = WAITING_AGENT;
    break;

  default:
    break;
  }

  if (state == AGENT_CONNECTED)
  {
    EXECUTE_EVERY_N_MS(3000, {
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      char buf[128];
      int torpedo_cur = torpedoServo.readMicroseconds();
      int grabber_cur = grabberServo.readMicroseconds();
      snprintf(buf, sizeof(buf), "ACTUATOR TICK [%lu ms] torpedo cur: %d target: %d | grabber cur: %d target: %d",
               (unsigned long)uxr_millis(), torpedo_cur, target_torpedo_us, grabber_cur, target_grabber_us);
      rosidl_runtime_c__String__assign(&log_msg.data, buf);
      RCSOFTCHECK(rcl_publish(&log_publisher, &log_msg, NULL));
    });
  }
  else
  {
    digitalWrite(LED_PIN, 0);
  }
}

#endif