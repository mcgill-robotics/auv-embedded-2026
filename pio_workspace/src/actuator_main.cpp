#ifdef ACTUATOR_H

#include "actuator_main.h"

#include <Arduino.h>
#include <Servo.h>

// Actuator board connections
constexpr uint8_t J3_PIN = 10;
constexpr uint8_t J4_PIN = 11;
constexpr uint8_t LED_PIN = 13;

// SER-2010 PWM range is 800-2200 us. Start with conservative positions.
constexpr int SERVO_MIN_US = 800;
constexpr int SERVO_MAX_US = 2200;
constexpr int SERVO_CENTER_US = 1500;
constexpr int POSITION_A_US = 1200;
constexpr int POSITION_B_US = 1800;

constexpr int STEP_US = 10;
constexpr unsigned long STEP_DELAY_MS = 20;
constexpr unsigned long HOLD_TIME_MS = 1000;

Servo j3Servo;
Servo j4Servo;
int currentPositionUs = SERVO_CENTER_US;

void writeBothServos(int pulseWidthUs)
{
  j3Servo.writeMicroseconds(pulseWidthUs);
  j4Servo.writeMicroseconds(pulseWidthUs);
}

void moveBothServosTo(int targetPositionUs)
{
  const int direction = (targetPositionUs > currentPositionUs) ? STEP_US : -STEP_US;

  while (currentPositionUs != targetPositionUs)
  {
    currentPositionUs += direction;

    if ((direction > 0 && currentPositionUs > targetPositionUs) ||
        (direction < 0 && currentPositionUs < targetPositionUs))
    {
      currentPositionUs = targetPositionUs;
    }

    writeBothServos(currentPositionUs);
    delay(STEP_DELAY_MS);
  }
}

void actuator_setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  j3Servo.attach(J3_PIN, SERVO_MIN_US, SERVO_MAX_US);
  j4Servo.attach(J4_PIN, SERVO_MIN_US, SERVO_MAX_US);

  // Begin at neutral so the SER-2010 does not jump to an endpoint at startup.
  writeBothServos(SERVO_CENTER_US);
  delay(2000);
}

void actuator_loop()
{
  moveBothServosTo(POSITION_A_US);
  digitalWrite(LED_PIN, LOW);
  delay(HOLD_TIME_MS);

  moveBothServosTo(POSITION_B_US);
  digitalWrite(LED_PIN, HIGH);
  delay(HOLD_TIME_MS);
}

#endif
