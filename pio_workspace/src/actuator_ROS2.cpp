#ifdef ACTUATOR_H

#include "actuator_main.h"

#include <Arduino.h>
#include <Servo.h>

#include <micro_ros_arduino.h>

#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/u_int16.h>
#include <std_msgs/msg/bool.h>

#define SERVO_PIN 9
#define LED_PIN 13

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){ error_loop(); }}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){} }

#define EXECUTE_EVERY_N_MS(MS, X)  do { \
  static volatile int64_t init = -1; \
  if (init == -1) { init = uxr_millis(); } \
  if (uxr_millis() - init > MS) { X; init = uxr_millis(); } \
} while (0)


// -------------------------------
// GLOBALS
// -------------------------------

Servo grabberServo;

// micro-ROS core handles
rclc_support_t support;
rcl_node_t node;
rcl_allocator_t allocator;

rcl_subscription_t position_subscriber;
std_msgs__msg__UInt16 position_msg;

rcl_subscription_t sweep_subscriber;
std_msgs__msg__Bool sweep_msg;

rclc_executor_t executor;

enum states {
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;


// -------------------------------
// ERROR BLINK
// -------------------------------
void error_loop() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
  }
  digitalWrite(LED_PIN, HIGH);
}


// -------------------------------
// SERVO CALLBACKS
// -------------------------------
void servo_position_callback(const void *msgin)
{
  const std_msgs__msg__UInt16 *msg = (const std_msgs__msg__UInt16 *) msgin;

  int position = constrain(msg->data, 0, 180);
  grabberServo.write(position);
}

void servo_sweep_callback(const void *msgin)
{
  const std_msgs__msg__Bool *msg = (const std_msgs__msg__Bool *) msgin;

  if (msg->data) {
    // sweep forward
    for (int pos = 0; pos <= 180; pos++) {
      grabberServo.write(pos);
      delay(10);
    }
  } else {
    // sweep backward
    for (int pos = 180; pos >= 0; pos--) {
      grabberServo.write(pos);
      delay(10);
    }
  }
}


// -------------------------------
// CREATE ENTITIES
// -------------------------------
bool create_entities()
{
  allocator = rcl_get_default_allocator();

  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  RCCHECK(rclc_node_init_default(
    &node,
    "actuator_node",
    "",
    &support
  ));

  RCCHECK(rclc_subscription_init_default(
    &position_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, UInt16),
    "/servo/position"
  ));

  RCCHECK(rclc_subscription_init_default(
    &sweep_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Bool),
    "/servo/sweep"
  ));

  executor = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor, &support.context, 2, &allocator));

  RCCHECK(rclc_executor_add_subscription(
    &executor,
    &position_subscriber,
    &position_msg,
    &servo_position_callback,
    ON_NEW_DATA
  ));

  RCCHECK(rclc_executor_add_subscription(
    &executor,
    &sweep_subscriber,
    &sweep_msg,
    &servo_sweep_callback,
    ON_NEW_DATA
  ));

  return true;
}


// -------------------------------
// DESTROY ENTITIES
// -------------------------------
void destroy_entities()
{
  rcl_subscription_fini(&position_subscriber, &node);
  rcl_subscription_fini(&sweep_subscriber, &node);
  rclc_executor_fini(&executor);
  rcl_node_fini(&node);
  rclc_support_fini(&support);
}


// -------------------------------
// SETUP
// -------------------------------
void actuator_setup()
{
  pinMode(LED_PIN, OUTPUT);

  // Attach servo to pin
  grabberServo.attach(SERVO_PIN);

  // micro-ROS transport
  Serial.begin(115200);
  set_microros_transports();
  delay(2000);

  // initialize message memory
  position_msg.data = 0;
  sweep_msg.data = false;

  state = WAITING_AGENT;
}


// -------------------------------
// MAIN LOOP
// -------------------------------
void actuator_loop()
{
  switch(state)
  {
    case WAITING_AGENT:
      EXECUTE_EVERY_N_MS(500,
        state = (rmw_uros_ping_agent(100, 1) == RMW_RET_OK) ?
                 AGENT_AVAILABLE : WAITING_AGENT;
      );
      break;

    case AGENT_AVAILABLE:
      state = (create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
      if (state == WAITING_AGENT) destroy_entities();
      break;

    case AGENT_CONNECTED:
      EXECUTE_EVERY_N_MS(200,
        state = (rmw_uros_ping_agent(100, 1) == RMW_RET_OK) ?
                 AGENT_CONNECTED : AGENT_DISCONNECTED;
      );
      if (state == AGENT_CONNECTED) {
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(50));
      }
      break;

    case AGENT_DISCONNECTED:
      destroy_entities();
      state = WAITING_AGENT;
      break;
  }

  digitalWrite(LED_PIN, (state == AGENT_CONNECTED) ? HIGH : LOW);
}

#endif
