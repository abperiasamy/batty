/*
  ultrasonic-hc-srf04.hpp: Ultrasonic Range Finder - HC-SRF04 (Virtuabotix).

  Author: Anand Babu Periasamy <ab@hyperbotics.org>
  Copyright (c) 2012 Anand Babu Periasamy

  This is free software; you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published
  by the Free Software Foundation; either version 3 of the License,
  or (at your option) any later version.

  Notes: This sensors is cheap, but accurate only for short
  distances. Use Maxbotix ultrasonic sensors if you need accuracy.
*/

#ifndef ULTRASONIC-HC-SRF04_HPP
#define ULTRASONIC-HC-SRF04_HPP

float ultrasonic_init_hc_srf04 (int echo_pin, int trigger_pin);
float ultrasonic_distance_hc_srf04 (int echo_pin, int trigger_pin);

#endif
