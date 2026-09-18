#include <Arduino.h>
#include "constants.hpp"
#include "TT_motor_lib.hpp"

#if COMPILE_SECTION == 3

#define SPEED 2000000.0

void setup() {
    // Set up everything
    Serial.begin(BAUD);

    pinMode(MOTOR_B_1A, OUTPUT);
    pinMode(MOTOR_B_1B, OUTPUT);

    Serial.println("Starting");
}

unsigned long tim;

void loop() {
    // Follow a sinusoidal for the speed of the motor
    tim = micros();
    int amp = (int)(sin(tim / SPEED) * 255.0);

    // "kick" it when its slow, so the motor doesn't get stuck
    amp = (abs(amp) < 15) ? ((amp < 0) ? -255 : 255) : amp;

    Serial.println(amp);

    move_motor(MOTOR_B_1A, MOTOR_B_1B, amp);
}

#endif
