#include "constants.hpp"
#include <Arduino.h>

float get_pot() {
  int sensorValue = analogRead(POT_PIN);
  float sensorVoltage = sensorValue * 3.3 / 4095.0;
  return sensorVoltage;
}
