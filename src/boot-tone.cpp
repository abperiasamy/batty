/*
  boot-tone.cpp: Play some meoldy on boot.

  Author: Anand Babu Periasamy <ab@unlocksmith.org>
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

  Based on Arduino.cc Tone Tutorial (Public Domain)
  URL: http://arduino.cc/en/Tutorial/tone
*/

#include <Arduino.h>
#include "boot-tone.h"

void boot_tone (int pin)
{
  // notes in the melody:
  int melody[] = {
    NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {
    4, 8, 8, 4,4,4,4,4 };

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++)
    {
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / noteDurations[thisNote];
      tone (pin, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay (pauseBetweenNotes);
      // stop the tone playing:
      noTone (pin);
    }
}
