---
title: ESP 32 Basics
author: Trevor Nichols
team: Group 6
---

# ESP 32 Basics

This is the first assignment working with the ESP32s. The goal of this lab is to make a
blinking LED.

## Process

Initialize the project with `pio project init`

Configure the board configuration within `platformio.ini`:

```ini
[platformio]
core_dir = .pio/core

[env:adafruit_feather_esp32_v2]
platform = espressif32@6.4.0
board = adafruit_feather_esp32_v2
framework = arduino
monitor_speed = 115200
```

> Note: I had to downgrade `espressif32` in order for there to not be compilation errors

To build, run `pio run`

To upload and monitor, run `pio run -t upload -t monitor`

## Reflection

This lab took ~30 mins, messing with the version downgrade took the most time out of
everything. I would say this assignment was also easy and I am still quite comfortable
with the course content.

## Video

https://youtu.be/nVxwisBlLJI

Here is a video link of the project working.
