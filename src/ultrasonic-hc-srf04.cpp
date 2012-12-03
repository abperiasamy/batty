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
#include "ultrasonic-hc-srf04.hpp"

float
hc_srf04_init (int echo_pin, int trigger_pin)
{
  pinMode (echo_pin, INPUT);
  pinMode (trigger_pin, OUTPUT);
}

float
hc_srf04_distance (int echo_pin, int trigger_pin)
{
  float distance, cm;

  unsigned int duration = 0; // initialize to be sure that it gets a valid 0 start

  digitalWrite (trigger_pin, LOW); // make sure the trigger is off
  delayMicroseconds (2);
  digitalWrite (trigger_pin, HIGH); // trigger the sensor
  delayMicroseconds (10);
  digitalWrite (trigger_pin, LOW); // turn off the trigger
  duration = float (pulseIn (echo_pin, HIGH)); // read the number of microseconds for echo

  /* Sound travels at 29.1 ųs/cm and we had to go there and back so divide by 2 */
  cm = (duration / 29.1) / 2;

  return cm;
}
