#include <Arduino.h>

#define LED_PIN 13
#define BAUD 115200

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(BAUD); // Start the Serial connection
}

void loop() {
  Serial.println("Hello"); // Say hello!

  digitalWrite(LED_PIN, HIGH); // LED On
  delay(250);                  // Wait half a second
  digitalWrite(LED_PIN, LOW);  // LED Off
  delay(250);                  // Wait half a second
  digitalWrite(LED_PIN, HIGH); // LED On
  delay(750);                  // Wait half a second
  digitalWrite(LED_PIN, LOW);  // LED Off
  delay(750);                  // Wait half a second
}
