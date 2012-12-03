/*
  ps1240_piezo_buzzer.hpp: Piezo Buzzer - PS1240.

  Author: Anand Babu Periasamy <ab@hyperbotics.org>
  Copyright (c) 2012 Anand Babu Periasamy

  This is free software; you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published
  by the Free Software Foundation; either version 3 of the License,
  or (at your option) any later version.
*/

#ifndef PS1240_PIEZO_BUZZER_HPP
#define PS1240_PIEZO_BUZZER_HPP

#define PS1240_BUZZER_FREQ 4000 /* Piezo Buzzer (PS1240) is loudest at 4 KHz. */

void ps1240_buzz (int pin, int duration);
void ps1240_buzz_freq (int pin, int duration, int freq);

#endif
