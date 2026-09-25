#include "TT_motor_lib.hpp"
#include "constants.hpp"
#include <Arduino.h>

#if COMPILE_SECTION == 2

void setup() {
  Serial.begin(BAUD);

  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_1B, OUTPUT);

  Serial.println("Starting");
}

void loop() {
  // --- SECTION 1: Clockwise (5s) ---

  Serial.println("Clockwise");
  move_motor(MOTOR_B_1A, MOTOR_B_1B, -255);
  delay(5000);

  // --- SECTION 2: Stop (2s) ---

  Serial.println("Stopped");
  move_motor(MOTOR_B_1A, MOTOR_B_1B, 0);
  delay(2000);

  // --- SECTION 3: Counterclockwise (5s) ---

  Serial.println("Counterclockwise");
  move_motor(MOTOR_B_1A, MOTOR_B_1B, 255);
  delay(5000);

  // --- SECTION 4: Stop (2s) ---

  Serial.println("Stopped");
  move_motor(MOTOR_B_1A, MOTOR_B_1B, 0);
  delay(2000);
}

#endif
