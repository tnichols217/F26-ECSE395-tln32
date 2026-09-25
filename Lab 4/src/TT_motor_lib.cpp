#include <Arduino.h>

// Rotate a motor in the given direction
// Positive is counterclockwise
void move_motor(int pinA, int pinB, int direction) {
  int a = (direction > 0) ? direction : 0;
  int b = (-direction > 0) ? -direction : 0;
  analogWrite(pinA, a);
  analogWrite(pinB, b);
}
