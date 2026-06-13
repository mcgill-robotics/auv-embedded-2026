#ifdef ACTUATOR_H

#include <Arduino.h>
#include <Servo.h>

#define TORPEDO_PIN 8

// Torpedo Positions
#define OPEN_ONE 1065  // shoot first torpedo, second is closed
#define CLOSED 1450 // both closed
#define OPEN_BOTH 1900 // shoots second torpedo, both open

// Declare Servo object
Servo torpedoServo;

// Function to move torpedo to a target position
// TO DO: rename targetUs variable to just "position" or something similar so not confused with time variable
void sweepTorpedo(int targetUs, int stepDelay =0.0001)
{
  int currentUs = torpedoServo.readMicroseconds();
  int step = (targetUs > currentUs) ? 50 : -50;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          // 10µs per step

  for (int us = currentUs; (step > 0) ? (us <= targetUs) : (us >= targetUs); us += step)
  {
    torpedoServo.writeMicroseconds(us);
    delay(stepDelay);
  }
  torpedoServo.writeMicroseconds(targetUs); // ensure we land exactly on target
    
}

// Setup function
void actuator_setup()
{
  torpedoServo.attach(TORPEDO_PIN); 
  moveTorpedo(CLOSED); // start at center
  delay(500);
}

// Move torpedo to specified position
void moveTorpedo(int position, int torpedoDelay=1000){
  sweepTorpedo(position);
  delay(torpedoDelay);
}

// Main loopss
void actuator_loop()
{
  moveTorpedo(CLOSED);
  moveTorpedo(OPEN_ONE);
  moveTorpedo(OPEN_BOTH);
}

#endif