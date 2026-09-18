#include <ESP32Servo.h>
#include <Arduino.h>
#include "constants.hpp"
#include "Servo_motor_lib.hpp"
// Don't forget to include the library!!
// From PlatfromIO library, search for ESP32 servo and add it to the project
#if COMPILE_SECTION == 6

// Define the servo and the pin it is connected to, what is your servo pin?
Servo* myServo = new Servo {};
// variable for random angle
int prevAngle = 0;
int randomAngle = 0;
// variable for random wait time
int randomTime;
// Variable for pulse width
int pulseWidth;

// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500;  // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

void setup() {
    Serial.begin(BAUD);
    // Attach the servo to the specified pin and set its pulse width range
    myServo->attach(SERVO_PIN, minPulseWidth, maxPulseWidth);

    // Set the PWM frequency for the servo
    myServo->setPeriodHertz(500); // Standard 50Hz servo
}

void loop() {
    // Pick a random angle between 0 and 180
    prevAngle = randomAngle;
    randomAngle = random(0, 180);
    randomTime = random(100, 3000);

    Serial.println(randomAngle);

    move_servo(myServo, minPulseWidth, maxPulseWidth, prevAngle, randomAngle, randomTime);
}

#endif
