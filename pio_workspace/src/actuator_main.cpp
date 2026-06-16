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
#include <rmw_microros/rmw_microros.h> // Needed for pinging the agent

// std msg type libraries
#include <std_msgs/msg/u_int8.h>

// Define torpedo Positions
#define OPEN_ONE 1065  // shoot first torpedo, second is closed
#define CLOSED 1450    // both closed
#define OPEN_BOTH 1900 // shoots second torpedo, both open

// Define pins on Teensy
#define LED_PIN 13
#define TORPEDO_PIN 8


// Macro for non-blocking timing in the state machine
#define EXECUTE_EVERY_N_MS(MS, X)  do { \
  static volatile int64_t init = -1; \
  if (init == -1) { init = uxr_millis();} \
  if (uxr_millis() - init > MS) { X; init = uxr_millis();} \
} while (0)

// Declare Servo objects
Servo torpedoServo;

// Declare microROS variables
rcl_subscription_t subscriber;
std_msgs__msg__UInt8 msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;


enum torpedo_positions {
  closed=0,
  shoot_one=1,
  shoot_two=2
} command;

// Forward declarations
bool create_entities();
void destroy_entities();

// Define states for the connection state machine
enum states {
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

// Allocations fail if USB port is disconnected and reconnected, need to manually TOTO the port
void disconnectUSB() {
  USB1_USBCMD = 0;
}
void connectUSB() {
  USB1_USBCMD = 1;
}


// Function to move torpedo to a target position
void sweepTorpedo(int targetPosition, int stepDelay = 1)
{
  int currentPosition = torpedoServo.readMicroseconds();
  int step = (targetPosition > currentPosition) ? 50 : -50;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  // 10µs per step

  for (int us = currentPosition; (step > 0) ? (us <= targetPosition) : (us >= targetPosition); us += step)
  {
    torpedoServo.writeMicroseconds(us);
    delay(stepDelay);
  }
  torpedoServo.writeMicroseconds(targetPosition); // ensure we land exactly on target
}

// Move torpedo to specified position
void moveTorpedo(int position, int torpedoDelay = 1000) {
  sweepTorpedo(position);
  delay(torpedoDelay);
}

// Callback when msg received
void torpedo_callback(const void * msgin) {
  const std_msgs__msg__UInt8 * msg = (const std_msgs__msg__UInt8 *)msgin;
  uint8_t command = msg->data;

  switch (command) {
    case closed:
      moveTorpedo(CLOSED); // 0 triggers moving to the closed position
      break;
    case shoot_one:
      moveTorpedo(OPEN_ONE); // 1 triggers shooting the first
      break;
    case shoot_two:
      moveTorpedo(OPEN_BOTH); // 2 triggers shooting the second torpedo
      break;
    default:
      // Ignore unmapped commands
      break;
  }
}

// Setup function
void actuator_setup()
{
  // LED for debugging
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  // Set transport to serial
  Serial.begin(115200);
  set_microros_transports();
  delay(500);

  // Set up torpedo servo
  torpedoServo.attach(TORPEDO_PIN); 
  moveTorpedo(CLOSED); // start at center
  delay(500);

  // Set initial msg to CLOSED position'
  msg.data = closed;

  // Initialize state machine
  state = WAITING_AGENT;
}

// Function to dynamically allocate ROS 2 entities when connected
bool create_entities()
{
  allocator = rcl_get_default_allocator();

  // Initialize support structure
  rcl_ret_t rc = rclc_support_init(&support, 0, NULL, &allocator);
  if (rc != RCL_RET_OK) return false;

  // Initialize node
  rc = rclc_node_init_default(&node, "torpedo_actuator_node", "", &support);
  if (rc != RCL_RET_OK) return false;

  // Initialize subscriber
  rc = rclc_subscription_init_default(
    &subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, UInt8),
    "torpedo_command"
  );
  if (rc != RCL_RET_OK) return false;

  // Initialize executor
  rc = rclc_executor_init(&executor, &support.context, 1, &allocator);
  if (rc != RCL_RET_OK) return false;

  rc = rclc_executor_add_subscription(&executor, &subscriber, &msg, &torpedo_callback, ON_NEW_DATA);
  if (rc != RCL_RET_OK) return false;

  return true;
}

// Function to safely destroy ROS 2 entities if connection drops
void destroy_entities()
{
  disconnectUSB();

  rmw_context_t * rmw_context = rcl_context_get_rmw_context(&support.context);
  (void) rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  rcl_subscription_fini(&subscriber, &node);
  rcl_node_fini(&node);
  rclc_executor_fini(&executor);
  rclc_support_fini(&support);

  connectUSB();
}

// Main loop
void actuator_loop()
{
  switch (state) {
    case WAITING_AGENT:
      // Ping agent every 500ms to see if it's there
      EXECUTE_EVERY_N_MS(500, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;);
      break;
      
    case AGENT_AVAILABLE:
      // Agent found, attempt to create node/subscriber
      state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
      if (state == WAITING_AGENT) {
        destroy_entities(); // Clean up if creation failed midway
      }
      break;
      
    case AGENT_CONNECTED:
      // Continuously check connection every 200ms
      EXECUTE_EVERY_N_MS(200, state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;);
      
      if (state == AGENT_CONNECTED) {
        // Only spin executor if still safely connected
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
      }
      break;
      
    case AGENT_DISCONNECTED:
      // Connection lost, destroy entities to avoid memory leaks and restart
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