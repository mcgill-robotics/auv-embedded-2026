#ifdef ACTUATOR_ROS1_H

#include "actuator_ros1_main.h"

#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 9

// Hitec D954SW pulse range
#define PULSE_MIN 900  // fully open
#define PULSE_MID 1500 // center
#define PULSE_MAX 2100 // fully closed

Servo grabberServo;

void sweepTo(int targetUs, int stepDelay = 15)
{
  int currentUs = grabberServo.readMicroseconds();
  int step = (targetUs > currentUs) ? 10 : -10; // 10µs per step

  for (int us = currentUs; (step > 0) ? (us <= targetUs) : (us >= targetUs); us += step)
  {
    grabberServo.writeMicroseconds(us);
    delay(stepDelay);
  }
  grabberServo.writeMicroseconds(targetUs); // ensure we land exactly on target
}

void actuator_ros1_setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  grabberServo.attach(SERVO_PIN, PULSE_MIN, PULSE_MAX); // tell the library the valid range
  delay(500);
  grabberServo.writeMicroseconds(PULSE_MID); // start at center
  delay(500);
}

void actuator_ros1_loop()
{
  sweepTo(PULSE_MIN); // open
  delay(1000);

  sweepTo(PULSE_MID); // center
  delay(1000);

  sweepTo(PULSE_MAX); // close
  delay(1000);
}

#endif