#include "constants.hpp"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 *makeDisplay() {
  Wire.begin(OLED_SDA, OLED_SCK);

  Adafruit_SSD1306 *disp =
      new Adafruit_SSD1306(SCREEN_W, SCREEN_H, &Wire, OLED_RESET);

  if (!disp->begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    delete disp; // Clean up memory
    return nullptr;
  }

  return disp;
}
