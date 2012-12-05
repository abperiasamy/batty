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

#ifndef ULTRASONIC-LV-EZ4_HPP
#define ULTRASONIC-LV-EZ4_HPP

void ultrasonic_init_lv_ez4 (int pin_an);
float ultrasonic_distance_lv_ez4 (int pin_an);

#endif
