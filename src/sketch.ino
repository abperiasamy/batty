/*
  sketch.ino: Batty Project - Turns distance in to human senses (vibration or beeps).

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

/* Uncomment only one of these two lines to pick approprite sensor. */
// #define LV_EZ4  /* Ultrasonic Range Finder - Maxbotix LV-EZ4. */
#define HC_SRF04  /*Virtuabotix Ultrasonic Sensor - HC-SRF04 */

/* Enable for testing purpose. */
#define BUZZ_OFF 1

/*************************************************************************/
/* This part of the code uses Ultrasonic Range Finder - Maxbotix LV-EZ4. */
/*************************************************************************/

#ifdef LV_EZ4

#include "ps1240_piezo_buzzer.h"
#include "boot-tone.h"
#include "ultrasonic-lv-ez4.h"

/* Piezo Buzzer - PS1240. */
#define PIN_DG_BUZZER_PS1240 8

/* Ultrasonic Range Finder - Maxbotix LV-EZ4. */
#define PIN_AN_ULTRASONIC_LV_EZ4  2

/* Vibration Motor - ROB-08449. */
#define PIN_AN_VIBE_MOTOR 4

void setup()
{
  Serial.begin (9600);
  ultrasonic_init_lv_ez4 (PIN_AN_ULTRASONIC_LV_EZ4);
  boot_tone (PIN_DG_BUZZER_PS1240);
}

void loop()
{
  float dist;
  dist = ultrasonic_distance_lv_ez4 (PIN_AN_ULTRASONIC_LV_EZ4);
  Serial.print ("Distance: ");
  Serial.print (dist);
  Serial.println (" cm");

  /*
  if ((dist > 5000) || (dist == 0))
    {
      delay (50);
      return;
    }
  */
  //   ps1240_buzz (PIN_DG_BUZZER_PS1240, sqrt ((unsigned int) dist));
#ifndef BUZZ_OFF
  ps1240_buzz (PIN_DG_BUZZER_PS1240, (unsigned int) dist/2);
#endif
}

#endif

/***********************************************************************/
/* This part of the code uses Virtuabotix Ultrasonic Sensor - HC-SRF04 */
/***********************************************************************/
#ifdef HC_SRF04

#include "boot-tone.h"
#include "ps1240_piezo_buzzer.h"
#include "ultrasonic-hc-srf04.h"

/* Piezo Buzzer - PS1240. */
#define PIN_DG_BUZZER_PS1240 8

/* Ultrasonic Range Finder - HC-SRF04. */
#define PIN_AN_ULTRASONIC_HC_SRF04_TRIGGER    2
#define PIN_AN_ULTRASONIC_HC_SRF04_ECHO       3

/* Vibration Motor - ROB-08449. */
#define PIN_AN_VIBE_MOTOR 4

void setup()
{
  Serial.begin (9600);
  ultrasonic_init_hc_srf04 (PIN_AN_ULTRASONIC_HC_SRF04_ECHO, PIN_AN_ULTRASONIC_HC_SRF04_TRIGGER);
  // vibe_motor_init_rob_08449 (PIN_AN_VIBE_MOTOR);
  boot_tone (PIN_DG_BUZZER_PS1240);
}

void loop()
{
  float dist;
  dist = ultrasonic_distance_hc_srf04 (PIN_AN_ULTRASONIC_HC_SRF04_ECHO, PIN_AN_ULTRASONIC_HC_SRF04_TRIGGER);
  Serial.print ("Distance: ");
  Serial.print (dist);
  Serial.println (" cm");

  if ((dist > 500) || (dist == 0))
    {
      delay (50);
      return;
    }

  //   ps1240_buzz (PIN_DG_BUZZER_PS1240, sqrt ((unsigned int) dist));
#ifndef BUZZ_OFF
  ps1240_buzz (PIN_DG_BUZZER_PS1240, (unsigned int) dist/2);
#endif

}

#endif
