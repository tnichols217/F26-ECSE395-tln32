#include "input.hpp"
#include "constants.hpp"
#include <Arduino.h>

bool get_touch(int pin) {
  int touch = touchRead(pin);
  return touch < TOUCH_THRESH;
}

inputs get_input() {
  return inputs{.up = get_touch(TOUCH_UP),
                .down = get_touch(TOUCH_DOWN),
                .left = get_touch(TOUCH_LEFT),
                .right = get_touch(TOUCH_RIGHT)};
}
