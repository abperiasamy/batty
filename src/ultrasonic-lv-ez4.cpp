/*
  ultrasonic-lv-ez4.hpp: Ultrasonic Range Finder - Maxbotix LV-EZ4.

  Author: Anand Babu Periasamy <ab@hyperbotics.org>
  Copyright (c) 2012 Anand Babu Periasamy

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see
  <http://www.gnu.org/licenses/>.

*/

#include <Arduino.h>
#include "ultrasonic-hc-srf04.h"

void
ultrasonic_init_lv_ez4 (int pin_an)
{
  pinMode (pin_an, INPUT);
}

float
ultrasonic_distance_lv_ez4 (int pin_an)
{
  float inch, cm;

  /* Analog pin yields (1 Vcc/512)/inch.
     i.e (5 Vcc/512)/inch = 9.765625 mV/inch. */
  inch = float (analogRead (pin_an))/1.953;

  /* Ultrasonic sensor LV-EZ4 range is limited from 6 to 245 inches. */
  inch = constrain (inch, 6, 245);

  cm = inch * 2.4;
  return (cm);
}
