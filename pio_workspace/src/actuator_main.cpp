#ifdef ACTUATOR_H

#include "actuator_main.h"

#include <Arduino.h>
#include <Servo.h>

#include <micro_ros_arduino.h>

#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <rmw_microros/rmw_microros.h>

// std msg type libraries
#include <std_msgs/msg/u_int8.h>

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

// Declare Servo objects
Servo torpedoServo;
Servo grabberServo;

bool micro_ros_init_successful;

rcl_subscription_t torpedo_subscriber;
std_msgs__msg__UInt8 torpedo_msg;

rcl_subscription_t grabber_subscriber;
std_msgs__msg__UInt8 grabber_msg;

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
} while (0)\

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

// Function to convert between ROS2 grabber positions and actual angles
int grabberMsgToAngle(uint8_t grabberPositionMsg) {

  // ((grabberMaxAngle - grabberMinAngle)/(maxMsg - minMsg))(inputMsg) + grabberMinAngle;
  int grabberAngle = (int)(float)(((GRABBER_OPEN - GRABBER_CLOSED)/(255.0f))*(grabberPositionMsg) + GRABBER_CLOSED);
  
  return grabberAngle;
}

// Function to move torpedo servo to a specific numeric position
void sweepTorpedo(int targetPosition)
{
  int stepDelay = 1;
  int currentPosition = torpedoServo.readMicroseconds();
  int step = (targetPosition > currentPosition) ? 50 : -50;

  for (int us = currentPosition; (step > 0) ? (us <= targetPosition) : (us >= targetPosition); us += step)
  {
    torpedoServo.writeMicroseconds(us);
    delay(stepDelay);
  }
  torpedoServo.writeMicroseconds(targetPosition);
}

// Function to move grabber servo to a specified angle
void sweepGrabber(uint8_t targetPositionMsg)
{
  // can be tuned
  int stepDelay = 2;

  // convert input message from ros (0-255) into a scale between open and closed
  int targetPositionAngle = grabberMsgToAngle(targetPositionMsg);

  int currentPosition = grabberServo.readMicroseconds();

  int step = (targetPositionAngle > currentPosition) ? 20 : -20;

  for (int us = currentPosition; (step > 0) ? (us <= targetPositionAngle) : (us >= targetPositionAngle); us += step)
  {
    grabberServo.writeMicroseconds(us);
    delay(stepDelay);
  }
  grabberServo.writeMicroseconds(targetPositionAngle);
}

// Function to parse torpedo msg and move torpedo servo accordingly
void torpedo_callback(const void *msgin)
{
  const std_msgs__msg__UInt8 *msg = (const std_msgs__msg__UInt8 *)msgin;
  torpedo_command = (torpedo_positions)msg->data;

  switch (torpedo_command)
  {
  case closed:
    sweepTorpedo(CLOSED);
    break;
  case shoot_one:
    sweepTorpedo(OPEN_ONE);
    break;
  case shoot_two:
    sweepTorpedo(OPEN_BOTH);
    break;
  default:
    break;
  }
}

// Function to parse grabber msg and move grabber servo accordingly
void grabber_callback(const void *msgin)
{
  const std_msgs__msg__UInt8 *msg = (const std_msgs__msg__UInt8 *)msgin;

  sweepGrabber(msg->data);
}

bool create_entities() {
  allocator = rcl_get_default_allocator();

  // create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "actuator_node", "", &support));

  RCCHECK(rclc_subscription_init_default(
    &torpedo_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, UInt8),
    "/actuators/torpedo"));
  
  RCCHECK(rclc_subscription_init_default(
    &grabber_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, UInt8),
    "/actuators/grabber"));


  // create executor
  executor = rclc_executor_get_zero_initialized_executor();
  RCCHECK(rclc_executor_init(&executor, &support.context, 100, &allocator)); // number arbitrarily set, idk what is the correct on yet, trial and error later on
  RCCHECK(rclc_executor_add_subscription(&executor, &torpedo_subscriber, &torpedo_msg, &torpedo_callback, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_subscription(&executor, &grabber_subscriber, &grabber_msg, &grabber_callback, ON_NEW_DATA));


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

  rmw_context_t * rmw_context = rcl_context_get_rmw_context(&support.context);
  (void) rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_subscription_fini(&torpedo_subscriber, &node);
  rcl_subscription_fini(&grabber_subscriber, &node);
  rcl_timer_fini(&timer);
  rclc_executor_fini(&executor);
  rcl_node_fini(&node);
  rclc_support_fini(&support);

  delay(25);
  connectUSB();
}

void actuator_setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  grabberServo.attach(GRABBER_PIN);
  delay(10);
  grabberServo.writeMicroseconds(GRABBER_OPEN);
  delay(10);

  torpedoServo.attach(TORPEDO_PIN);
  delay(10);
  torpedoServo.writeMicroseconds(CLOSED);
  delay(10);

  // Configure serial transport
  Serial.begin(115200);
  set_microros_transports();
  delay(2000);

  // allocates correct message sizes and initialzies to 0, required or crashes
  torpedo_msg.data = closed;
  grabber_msg.data = grabber_open;

  // first state
  state = WAITING_AGENT;
}

void actuator_loop() {
  switch (state) {
    case WAITING_AGENT:
      EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
      break;
    case AGENT_AVAILABLE:
      state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
      if (state == WAITING_AGENT) {
        destroy_entities();
      };
      break;
    case AGENT_CONNECTED:
      EXECUTE_EVERY_N_MS(50, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
      if (state == AGENT_CONNECTED) {
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
      } else {
      }
      break;
    case AGENT_DISCONNECTED:
      destroy_entities();
      state = WAITING_AGENT;
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
