#include <Arduino.h>
#include <ESP32Servo.h>

double easeInOutCubic(double pos) {
  // The same function as the easeInOutCubic CSS transition
  return pos < 0.5 ? (4.0 * pow(pos, 3)) : (1 - pow(-2.0 * pos + 2.0, 3) / 2.0);
}

void move_servo(Servo *myServo, int minPulse, int maxPulse, int oldAngle,
                int angle, int time) {
  unsigned long length = time * 1000;
  unsigned long start_tim = micros();
  unsigned long end_tim = start_tim + length;
  unsigned long tim = micros();
  while (tim < end_tim) {
    // Map time to progress
    double progress = (double)(tim - start_tim) / (double)length;
    // Smoothen progress
    double smoothProg = easeInOutCubic(progress);
    // Map progress to angle (double)
    double targetAngle =
        smoothProg * (double)(angle - oldAngle) + (double)(oldAngle);
    // Map angle to a pulse width (int)
    int pulseWidth =
        targetAngle / (double)180 * (double)(maxPulse - minPulse) + minPulse;
    // Update position
    myServo->writeMicroseconds(pulseWidth);
    // Update tim variable
    tim = micros();
  }
}
