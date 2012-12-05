/*
  ultrasonic-hc-srf04.hpp: Ultrasonic Range Finder - HC-SRF04 (Virtuabotix).

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

  Notes: This sensors is cheap, but accurate only for short
  distances. Use Maxbotix ultrasonic sensors if you need accuracy.
*/

#ifndef ULTRASONIC-HC-SRF04_HPP
#define ULTRASONIC-HC-SRF04_HPP

float ultrasonic_init_hc_srf04 (int echo_pin_an, int trigger_pin_an);
float ultrasonic_distance_hc_srf04 (int echo_pin_an, int trigger_pin_an);

#endif
