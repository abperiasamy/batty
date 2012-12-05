/*
  ps1240_piezo_buzzer.hpp: Piezo Buzzer - PS1240.

  Author: Anand Babu Periasamy <ab@hyperbotics.org>
  Copyright (c) 2012 Anand Babu Periasamy

  This is free software; you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published
  by the Free Software Foundation; either version 3 of the License,
  or (at your option) any later version.
*/

#include <Arduino.h>
#include "ps1240_piezo_buzzer.h"

void
ps1240_buzz (int pin, int duration)
{
  ps1240_buzz_freq (pin, duration, PS1240_BUZZER_FREQ);
}

void
ps1240_buzz_freq (int pin, int duration, int freq)
{
  tone (pin, freq);
  delay (duration);
  noTone (pin);
  delay (100);
}
