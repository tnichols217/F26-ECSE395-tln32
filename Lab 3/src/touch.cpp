#include "constants.hpp"
#include <Arduino.h>

bool process_touch() {
  int sensorValue = analogRead(TOUCH_PIN);
  return sensorValue > 2000;
}
