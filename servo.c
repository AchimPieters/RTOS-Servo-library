/**

   Copyright 2022 Achim Pieters | StudioPieters®

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 **/


#include <FreeRTOS.h>
#include <esp/uart.h>
#include <esp8266.h>
#include <pwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <task.h>
#include "servo.h"

//Define your PWM Pin here
#define PWM_GPIO 13

// My SG90 works on 500µs ~ 2650µs (spec: 500µ ~ 2400µ)
uint16_t calc_duty_from_angle(int angle) {
  return (0.025 + (0.1325 - 0.025) * (double)angle / 180) * UINT16_MAX;
}

void servo_init() {
  printf("pwm_init(1, [%d])\n", PWM_GPIO);

  uint8_t pins[1] = {PWM_GPIO};
  pwm_init(1, pins, false);

  printf("pwm_set_freq(50)     # 50 Hz\n");
  pwm_set_freq(50);
}

void rotate_task(void *angle_ptr) {
  static bool running = false;
  int angle = *((int*)angle_ptr);
  free(angle_ptr);

  while (running) {
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
  running = true;

  printf("rotate servo to angle %d\n", angle);
  pwm_set_duty(calc_duty_from_angle(angle));
  pwm_start();
  vTaskDelay(500 / portTICK_PERIOD_MS);
  pwm_stop();
  vTaskDelay(50 / portTICK_PERIOD_MS);

  running = false;
  vTaskDelete(NULL);
}

void servo_rotate_to_angle(int angle) {
  int *angle_ptr = malloc(sizeof(int));
  *angle_ptr = angle;
  xTaskCreate(rotate_task, "rotate_task", 256, angle_ptr, 2, NULL);
}
