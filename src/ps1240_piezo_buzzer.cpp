/*
  ps1240_piezo_buzzer.hpp: Piezo Buzzer - PS1240.

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
#include "ps1240_piezo_buzzer.h"

void
ps1240_buzz (int pin_dg, int duration)
{
  ps1240_buzz_freq (pin_dg, duration, PS1240_BUZZER_FREQ);
}

void
ps1240_buzz_freq (int pin_dg, int duration, int freq)
{
  tone (pin_dg, freq);
  delay (duration);
  noTone (pin_dg);
  delay (100);
}
