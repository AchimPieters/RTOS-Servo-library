# RTOS - Servo library

Allows ESP8266 & ESP32 boards to control  a servo , tone and analogWrite motors using ESP semantics. 
This library can control a many types of servos. It makes use of the ESPXX PWM timers.

## PWM Pins
ESP8266 allows software PWM in all I/O pins: GPIO0 to GPIO16. PWM signals on ESP8266 have 10-bit resolution.

The ESP32 LED PWM controller has 16 independent channels that can be configured to generate PWM signals with different properties. All pins that can act as outputs can be used as PWM pins (GPIOs 34 to 39 can’t generate PWM).

You can change the PWM pin in servo.c Default PWM pin is GPIO 13

## License

MIT licensed. See the bundled LICENSE file for more details.










