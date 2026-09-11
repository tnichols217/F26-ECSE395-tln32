#include <Arduino.h>
// Include our functions and constants
#include "constants.hpp"
#include "potentiometer.hpp"
#include "touch.hpp"

void setup() {
  Serial.begin(BAUD);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  char line[100];
  // Get touch and potentiometer readings
  bool touch = process_touch();
  float pot = get_pot();
  // Activate LED based on touch
  digitalWrite(LED_PIN, touch);
  // Generate output statement
  sprintf(line, "Touch: %-15s    Potentiometer: %.2f",
          touch ? "Touch detected!" : "No touch :(", pot);
  Serial.println(line);
  // Wait 100ms before next check
  delay(MS_DELAY);
}
