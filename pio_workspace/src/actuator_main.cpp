#ifdef ACTUATOR_H

#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 8

// Hitec D954SW pulse range
#define PULSE_MIN 1065  // fully open
#define PULSE_MID 1450 // center
#define PULSE_MAX 1900 // fully closed

Servo grabberServo;

void sweepTo(int targetUs, int stepDelay =0.0001)
{
  int currentUs = grabberServo.readMicroseconds();
  int step = (targetUs > currentUs) ? 50 : -50;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          // 10µs per step

  for (int us = currentUs; (step > 0) ? (us <= targetUs) : (us >= targetUs); us += step)
  {
    grabberServo.writeMicroseconds(us);
    delay(stepDelay);
  }
  grabberServo.writeMicroseconds(targetUs); // ensure we land exactly on target
}

void actuator_setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  grabberServo.attach(SERVO_PIN, PULSE_MIN, PULSE_MAX); // tell the library the valid range
  delay(500);
  grabberServo.writeMicroseconds(PULSE_MID); // start at center
  delay(500);
}
void resetstate(){
  sweepTo(PULSE_MID);
  delay(1000);
}

void shootOne(){
  sweepTo(PULSE_MIN);
  delay(1000);
}

void shootTwo(){
  sweepTo(PULSE_MAX);
  delay(1000);
}

void actuator_loop()
{
  resetstate();
  shootOne();
  shootTwo();

}

#endif