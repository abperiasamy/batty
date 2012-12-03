/*
  sketch.ino: Batty Project - Turns distance in to human senses (vibration or beeps).

  Author: Anand Babu Periasamy <ab@hyperbotics.org>
  Copyright (c) 2012 Anand Babu Periasamy

  This is free software; you can redistribute it and/or modify
  it under the terms of the GNU Affero General Public License as published
  by the Free Software Foundation; either version 3 of the License,
  or (at your option) any later version.
*/


#define LV_EZ4
// #define HC_SRF04

#ifdef LV_EZ4

#include "ps1240_piezo_buzzer.hpp"
#include "boot-tone.hpp"
#include "ultrasonic-lv-ez4.hpp"

/* Piezo Buzzer - PS1240 */
#define BUZZER_PS1240_PIN 8

/* Ultrasonic Range Finder - Maxbotix LV-EZ4. */
#define ULTRASONIC_LV_EZ4_AN_PIN  5

void setup()
{
  Serial.begin (9600);
  boot_tone (BUZZER_PS1240_PIN);
}

void loop()
{
  float dist;
  dist = lv_ez4_distance (ULTRASONIC_LV_EZ4_AN_PIN);
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
  //   ps1240_buzz (BUZZER_PS1240_PIN, sqrt ((unsigned int) dist));
  ps1240_buzz (BUZZER_PS1240_PIN, (unsigned int) dist);
}

#endif

#ifdef HC_SRF04
/* This part of the code uses Virtuabotix Ultrasonic Sensor - HC-SRF04 */

#include "boot-tone.hpp"
#include "ps1240_piezo_buzzer.hpp"
#include "ultrasonic-hc-srf04.hpp"

/* Piezo Buzzer - PS1240 */
#define BUZZER_PS1240_PIN 8

/* Ultrasonic Range Finder - HC-SRF04. */
#define ULTRASONIC_HC_SRF04_TRIGGER_PIN    2
#define ULTRASONIC_HC_SRF04_ECHO_PIN       3

void setup()
{
  Serial.begin (9600);
  hc_srf04_init (ULTRASONIC_HC_SRF04_ECHO_PIN, ULTRASONIC_HC_SRF04_TRIGGER_PIN);
  boot_tone (BUZZER_PS1240_PIN);
}

void loop()
{
  float dist;
  dist = hc_srf04_distance (ULTRASONIC_HC_SRF04_ECHO_PIN, ULTRASONIC_HC_SRF04_TRIGGER_PIN);
  Serial.print ("Distance: ");
  Serial.print (dist);
  Serial.println (" cm");

  if ((dist > 500) || (dist == 0))
    {
      delay (50);
      return;
    }

  //   ps1240_buzz (BUZZER_PS1240_PIN, sqrt ((unsigned int) dist));
  ps1240_buzz (BUZZER_PS1240_PIN, (unsigned int) dist);
}

#endif
