#include <Arduino.h>
#include "constants.hpp"

#if COMPILE_SECTION == 1

void setup() {
    pinMode(MOTOR_B_1A, OUTPUT);
    pinMode(MOTOR_B_1B, OUTPUT);
}

void loop() {
    // Spin one way
    analogWrite(MOTOR_B_1A, 0);
    analogWrite(MOTOR_B_1B, 255);

    delay(1000);

    // Spin the other way
    analogWrite(MOTOR_B_1A, 255);
    analogWrite(MOTOR_B_1B, 0);

    delay(1000);
}

#endif
