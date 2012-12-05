/*
  ultrasonic-lv-ez4.hpp: Ultrasonic Range Finder - Maxbotix LV-EZ4.

  Author: Anand Babu Periasamy <ab@hyperbotics.org>
  Copyright (c) 2012 Anand Babu Periasamy

  This is free software; you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published
  by the Free Software Foundation; either version 3 of the License,
  or (at your option) any later version.
*/

#include <Arduino.h>
#include "ultrasonic-hc-srf04.h"

/* Ultrasonic Range Finder - Maxbotix LV-EZ4. */
float
ultrasonic_distance_lv_ez4 (int pin)
{
  float inch, cm;
  inch = float (analogRead (pin))/1.953;
  cm = inch * 2.4;
  return (cm);
}
