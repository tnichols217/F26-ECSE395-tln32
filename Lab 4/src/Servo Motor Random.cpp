#include "constants.hpp"
#include <Arduino.h>
#include <ESP32Servo.h>
// Don't forget to include the library!!
// From PlatfromIO library, search for ESP32 servo and add it to the project
#if COMPILE_SECTION == 5

// Define the servo and the pin it is connected to, what is your servo pin?
Servo myServo;
// variable for random angle
int randomAngle;
// variable for random wait time
int randomWait;
// Variable for pulse width
int pulseWidth;

// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500;  // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

void setup() {
  Serial.begin(BAUD);
  // Attach the servo to the specified pin and set its pulse width range
  myServo.attach(SERVO_PIN, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo
  myServo.setPeriodHertz(50); // Standard 50Hz servo
}

void loop() {
  // Pick a random angle between 0 and 180
  randomAngle = random(0, 180);
  // Map 0 to the min pulse and 180 to the max pulse, so the servo understands
  // the signal
  pulseWidth = map(randomAngle, 0, 180, minPulseWidth, maxPulseWidth);
  myServo.writeMicroseconds(pulseWidth); // writing pulse width to servo

  Serial.println(randomAngle);
  randomWait = random(100, 1000);

  delay(randomWait); // change delay to your own preference
}

#endif
