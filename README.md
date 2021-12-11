# RTOS - Servo library

Allows ESP8266 & ESP32 boards to control  a servo . 
This library can control a many types of servos. It makes use of the ESPXX PWM timers.

[![GitHub All Releases](https://img.shields.io/github/downloads/AchimPieters/RTOS-Servo-library/total?color=green)](https://github.com/AchimPieters/RTOS-Servo-library/releases) 
[![GitHub license](https://img.shields.io/badge/License-MIT-yellow.svg)](https://raw.githubusercontent.com/hyperion-project/hyperion.ng/master/LICENSE)
[![GitHub license](https://img.shields.io/github/v/release/AchimPieters/RTOS-Servo-library)](https://img.shields.io/github/v/release/AchimPieters/RTOS-Servo-library)
[![Donate](https://img.shields.io/badge/donate-PayPal-blue.svg)](https://paypal.me/AJFPieters)

## PWM Pins
ESP8266 allows software PWM in all I/O pins: GPIO0 to GPIO16. PWM signals on ESP8266 have 10-bit resolution.

The ESP32 LED PWM controller has 16 independent channels that can be configured to generate PWM signals with different properties. All pins that can act as outputs can be used as PWM pins (GPIOs 34 to 39 can’t generate PWM).

You can change the PWM pin in <b><i>servo.c</i></b>. The default PWM pin is `GPIO 13`

## License

MIT licensed. See the bundled [LICENSE file](https://github.com/AchimPieters/RTOS-Servo-library/blob/main/LICENSE) for more details.

Copyright © 2022 StudioPieters<sup>®</sup> | https://www.studiopieters.nl











