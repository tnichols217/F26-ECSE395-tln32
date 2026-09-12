---
title: ESP32 Playing With Sensors
author: Trevor Nichols
team: Group 6
---

# Playing with Sensors

We will be utilizing the same methods for building, uploading, and monitoring the ESP 32
as Lab 2, on Linux:

- To build, run `pio run`
- To upload and monitor, run `pio run -t upload -t monitor`

## Files

The `potentiometer.cpp` file contains the code for monitoring a potentiometer, it
provides one function for returning the voltage read.

The `touch.cpp` file contains code for checking if the touch sensor is touched, it
provides one function the returns a boolean of touched or not.

The `main.cpp` file glues everything together and manages the Serial connection.

## Demo

The demo can be found at

[https://youtube.com/shorts/w-wwR3czGPI](https://youtube.com/shorts/w-wwR3czGPI)

## Reflection

This lab also took about ~30 mins, majority of the time was just spent cleaning up and
making the code organized. I would rate this as low difficulty and I still remain
comfortable with the course content.
