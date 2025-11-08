#ifdef ACTUATOR_H

#include "actuator_main.h"

#include <Arduino.h>
#include <Servo.h>

// ROS2 micro-ROS includes - replaced ros.h with micro-ROS client library
#include <micro_ros_arduino.h>  //ROS 2
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

// ROS 2 still uses std_msgs library
#include <std_msgs/msg/u_int16.h>
#include <std_msgs/msg/bool.h>

// servo pin definition
const int SERVO_PIN = 9;

// ROS2 entities - replaced ros::NodeHandle with individual ROS2 components
rcl_node_t node;                        // ROS2 node (replaces NodeHandle)
rcl_subscription_t position_subscriber; // Position subscription object
rcl_subscription_t sweep_subscriber;    // Sweep subscription object
rclc_executor_t executor;               // Executor to handle callbacks
rclc_support_t support;                 // Support object for initialization
rcl_allocator_t allocator;              // Memory allocator

// ROS2 message objects - must be declared globally for callbacks
std_msgs__msg__UInt16 position_msg;
std_msgs__msg__Bool sweep_msg;

// create grabber servo object
Servo grabberServo;

// Error handling macro - ROS2 has different error handling approach
#define RCCHECK(fn)              \
  {                              \
    rcl_ret_t temp_rc = fn;      \
    if ((temp_rc != RCL_RET_OK)) \
    {                            \
      error_loop();              \
    }                            \
  }
#define RCSOFTCHECK(fn)          \
  {                              \
    rcl_ret_t temp_rc = fn;      \
    if ((temp_rc != RCL_RET_OK)) \
    {                            \
    }                            \
  }

// Error handling function - blinks LED on error
void error_loop()
{
  while (1)
  {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(100);
  }
}

// ROS2 callback for servo position - signature changed from ROS1
// ROS2 callbacks receive const void* that must be cast to message type
void servoPosition_CB(const void *msgin)
{
  const std_msgs__msg__UInt16 *msg = (const std_msgs__msg__UInt16 *)msgin;
  // constrain servo position to valid range (0-180 degrees)
  int position = constrain(msg->data, 0, 180); // Changed msg.data to msg->data (pointer access)
  grabberServo.write(position);
}

// ROS2 callback for servo sweep - signature changed from ROS1
void servoSweep_CB(const void *msgin)
{
  const std_msgs__msg__Bool *msg = (const std_msgs__msg__Bool *)msgin;

  if (msg->data)
  { // Changed msg.data to msg->data (pointer access)
    // sweep from 0 to 180 degrees
    for (int pos = 0; pos <= 180; pos += 1)
    {
      grabberServo.write(pos);
      delay(15);
      // In ROS2, executor spins automatically, but we can still call it for responsiveness
      rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1));
    }
  }
  else
  {
    // sweep from 180 to 0 degrees
    for (int pos = 180; pos >= 0; pos -= 1)
    {
      grabberServo.write(pos);
      delay(15);
      // Check for new messages during sweep to maintain responsiveness
      rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1));
    }
  }
}

// setup function
void actuator_setup()
{
  // Configure serial transport for micro-ROS - required before any ROS2 operations
  set_microros_transports();

  // pwm teensy pin connected to grabber
  pinMode(SERVO_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT); // For error indication

  // attach servo object to teensy pin and check for success
  if (grabberServo.attach(SERVO_PIN))
  {
    // servo attached successfully
  }
  else
  {
    // servo attachment failed - could add LED blink or error handling here
  }

  // Small delay to ensure transport is ready
  delay(2000);

  // Initialize micro-ROS allocator - required for all ROS2 operations
  allocator = rcl_get_default_allocator();

  // Initialize support object - replaces nh.initNode()
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // Create ROS2 node - equivalent to NodeHandle in ROS1
  RCCHECK(rclc_node_init_default(&node, "actuator_node", "", &support));

  // Create position subscriber - topic name and QoS settings
  // ROS2 uses QoS (Quality of Service) policies instead of simple topic names
  RCCHECK(rclc_subscription_init_default(
      &position_subscriber,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, UInt16),
      "servo/position")); // Topic name matches ROS1 version

  // Create sweep subscriber
  RCCHECK(rclc_subscription_init_default(
      &sweep_subscriber,
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Bool),
      "servo/sweep")); // Topic name matches ROS1 version

  // Initialize executor with 2 handles (one for each subscription)
  // Executor replaces the spinOnce() pattern from ROS1
  RCCHECK(rclc_executor_init(&executor, &support.context, 2, &allocator));

  // Add subscriptions to executor with their callbacks
  RCCHECK(rclc_executor_add_subscription(
      &executor,
      &position_subscriber,
      &position_msg,
      &servoPosition_CB,
      ON_NEW_DATA)); // Only call callback when new data arrives

  RCCHECK(rclc_executor_add_subscription(
      &executor,
      &sweep_subscriber,
      &sweep_msg,
      &servoSweep_CB,
      ON_NEW_DATA));
}

// Main loop - executor handles callbacks automatically
void actuator_loop()
{
  // Spin executor to process callbacks - replaces nh.spinOnce()
  // RCL_MS_TO_NS converts milliseconds to nanoseconds (ROS2 uses nanosecond timing)
  RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1)));
  delay(1);
}

#endif