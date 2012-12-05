/*
  ultrasonic-hc-srf04.cpp: Ultrasonic Range Finder - HC-SRF04 (Virtuabotix).

  Author: Anand Babu Periasamy <ab@hyperbotics.org>
  Copyright (c) 2012 Anand Babu Periasamy

  This is free software; you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published
  by the Free Software Foundation; either version 3 of the License,
  or (at your option) any later version.
*/

#include <Arduino.h>
#include "ultrasonic-hc-srf04.h"

float
ultrasonic_init_hc_srf04 (int echo_pin, int trigger_pin)
{
  pinMode (echo_pin, INPUT);
  pinMode (trigger_pin, OUTPUT);
}

float
ultrasonic_distance_hc_srf04 (int echo_pin, int trigger_pin)
{
  float distance, cm;

  unsigned int duration = 0; // initialize to be sure that it gets a valid 0 start

  digitalWrite (trigger_pin, LOW); // make sure the trigger is off
  delayMicroseconds (2);
  digitalWrite (trigger_pin, HIGH); // trigger the sensor
  delayMicroseconds (10);
  digitalWrite (trigger_pin, LOW); // turn off the trigger
  duration = pulseIn (echo_pin, HIGH); // read the number of microseconds for echo

  /*
    Speed of sound at sea level: 340.29 m/s
    Convert m/s to cm/us = 0.034029 cm/us

     1 us  -> 0.034029 cm
     t us -> ? cm

     x = t * 0.034029 cm/us

     t is duration for the round-trip. t/2 is the actual distance to object.
     x = t/2 * 0.034029 cm/us
     x = t * 0.0170145 cm/us (pre-calculate to save micro-controller cycles).
   */

  /* Note: others seem to use (x * 1/2 * 1/27.6233) = 0.0181006613 */
  cm = duration * 0.0170145;

  return cm;
}
