#include <Ultrasonic.h>
#include "pitches.h"


#define LV_EZ4   /* High-end Ultrasonic Range Finder - LV-EZ4 (Maxbotix). */
// #define HC_SRF04 /* Ultrasonic Range Finder - HC-SRF04 (Virtuabotix). */


#define BUZZER_PIN 8
#define BUZZER_FREQ 4000 /* Piezo Buzzer (PS1240) is loudest at 4 KHz. */

/* Ultrasonic Range Finder - Maxbotix LV-EZ4. */
#define ULTRASONIC_LV_EZ4_AN_PIN  4

/* Ultrasonic Range Finder - HC-SRF04. */
#define ULTRASONIC_HC_SRF04_TRIGGER_PIN    2
#define ULTRASONIC_HC_SRF04_ECHO_PIN       3

static void boot_splash() {
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
      tone (8, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay (pauseBetweenNotes);
      // stop the tone playing:
      noTone (8);
    }
}

#ifdef LV_EZ4

/* Ultrasonic Range Finder - Maxbotix LV-EZ4. */
static inline float
lv_ez4_distance () {
  float d, cm;           // Converted to cm
  d = analogRead (ULTRASONIC_LV_EZ4_AN_PIN); // Read the analog value
  cm = (d / 2) * 2.4; // Convert the value to centimeters inch = d/2;
  return (cm);
}
#define distance() lv_ez4_distance ()

#elif defined HC_SRF04

/* Ultrasonic Range Finder - HC-SRF04. */
Ultrasonic ultrasonic (ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);
static inline float
hc_srf04_distance ()
{
  float cm;
  long microsec = ultrasonic.timing ();
  cm = ultrasonic.convert (microsec, Ultrasonic::CM);
  return cm;
}
#define distance() lv_hc_srf04_distance ()

#endif

static inline void
buzz (unsigned int duration)
{
  tone (BUZZER_PIN, BUZZER_FREQ);

  Serial.print ("Buzz Duration: ");
  Serial.println (duration);

  delay (duration);
  noTone (BUZZER_PIN);
  // delay (duration);
  delay (100);
}

void setup()
{
  boot_splash ();
}

void loop()
{
  float dist;
  dist = distance ();
  Serial.print ("Distance(CM): ");
  Serial.println (dist);

  if ((dist > 500) || (dist == 0))
    {
      delay (50);
      return;
    }
  buzz (((unsigned int)dist));
  //  delay (2000);
}
