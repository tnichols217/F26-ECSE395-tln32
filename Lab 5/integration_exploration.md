---
title: ESP32 Integration Exploration
author: Trevor Nichols
team: Group 6
---

# Integration Exploration

This is our final assignment with the ESP32, working on integrating sensors and
actuators. Similar to other labs, the process to upload to the ESP is the exact same,
with the `pio` command.

## To run

- Same as the other labs, simply run `pio run -t upload -t monitor` to build, upload,
  and watch the serial.

## Details

- Sensors: 4 capacitive touch pins
- Actuators: OLED screen
- All code is found in the `src` directory within this directory
- The relevant game subsections are inn their own files:
  - `main` is the main program that connects the pieces
  - `screen` manages the OLED screen and initializing the connection
  - `game` manages game state and game functions
  - `input` manages the capacitive touch sensors

## Reflection

This lab took about 2 hours, I would say this was a decently more difficult lab compared
to the rest, primarily voluntarily. The difficult thing was finding documentation on the
pins and capabilities of the ESP32 we have, since the capacitive touch pins were not
documented correctly. I am still comfortable with the course content.
