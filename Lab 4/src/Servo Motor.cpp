#include "constants.hpp"
#include <Arduino.h>
#include <ESP32Servo.h>
// Don't forget to include the library!!
// From PlatfromIO library, search for ESP32 servo and add it to the project

// Define the servo and the pin it is connected to, what is your servo pin?

#if COMPILE_SECTION == 4

Servo myServo;

// Define the minimum and maximum pulse widths for the servo
// A smaller range means we can't use the full range of the actual servo
const int minPulseWidth = 1000; // 1 ms
const int maxPulseWidth = 2000; // 2 ms
const int delayTime = 50;

void setup() {
  Serial.begin(BAUD);
  // Attach the servo to the specified pin and set its pulse width range
  myServo.attach(SERVO_PIN, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo
  myServo.setPeriodHertz(200); // Standard 50Hz servo
}

void loop() {
  // Rotate the servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    Serial.println(angle);
    int pulseWidth;
    // the map function is a puction that maps 0 degrees to 500 pulse width, and
    // 180 degrees to 2500 pulse width map(angle, min angle, max angle, min
    // pulse width, max pulse width)
    pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);
    delay(delayTime);
  }

  // Rotate the servo from 180 to 0 degrees
  // There was a bug     here   vv   in the example code, fixed the condition
  for (int angle = 180; angle >= 0; angle--) {
    Serial.println(angle);
    int pulseWidth;
    // the map function is a puction that maps 0 degrees to 500 pulse width, and
    // 180 degrees to 2500 pulse width map(angle, min angle, max angle, min
    // pulse width, max pulse width)
    pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth);
    myServo.writeMicroseconds(pulseWidth);
    delay(delayTime);
  }
}

#endif
