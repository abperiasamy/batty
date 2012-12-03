#include "pitches.h"

/* Uncomment one of these sensors at a time. */
// #define LV_EZ4   /* High-end Ultrasonic Range Finder - LV-EZ4 (Maxbotix). */
#define HC_SRF04 /* Ultrasonic Range Finder - HC-SRF04 (Virtuabotix). */

#define BUZZER_PIN 8
#define BUZZER_FREQ 4000 /* Piezo Buzzer (PS1240) is loudest at 4 KHz. */

/* Ultrasonic Range Finder - Maxbotix LV-EZ4. */
#define ULTRASONIC_LV_EZ4_AN_PIN  5

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
lv_ez4_distance ()
{
  float inch, cm;
  inch = float (analogRead (ULTRASONIC_LV_EZ4_AN_PIN))/1.953;
  cm = inch * 2.4;
  return (cm);
}
#define distance() lv_ez4_distance ()

#elif defined HC_SRF04 /* Ultrasonic Range Finder - HC-SRF04. */
static inline float
hc_srf04_init ()
{
  pinMode(ULTRASONIC_HC_SRF04_ECHO_PIN, INPUT);
  pinMode (ULTRASONIC_HC_SRF04_TRIGGER_PIN, OUTPUT);
}

static inline float
hc_srf04_distance ()
{
  float distance, cm;

  unsigned int duration = 0; // initialize to be sure that it gets a valid 0 start

  digitalWrite (ULTRASONIC_HC_SRF04_TRIGGER_PIN, LOW); // make sure the trigger is off
  delayMicroseconds (2);
  digitalWrite (ULTRASONIC_HC_SRF04_TRIGGER_PIN, HIGH); // trigger the sensor
  delayMicroseconds (10);
  digitalWrite (ULTRASONIC_HC_SRF04_TRIGGER_PIN, LOW); // turn off the trigger
  duration = float (pulseIn (ULTRASONIC_HC_SRF04_ECHO_PIN, HIGH)); // read the number of microseconds for echo

  /* Sound travels at 29.1 ųs/cm and we had to go there and back so divide by 2 */
  cm = (duration / 29.1) / 2;

  return cm;
}
#define distance() hc_srf04_distance ()

#endif

static inline void
buzz (unsigned int duration)
{
  tone (BUZZER_PIN, BUZZER_FREQ);

  // Serial.print ("Buzz Duration: ");
  // Serial.println (duration);

  delay (duration);
  noTone (BUZZER_PIN);
  // delay (duration);
  delay (100);
}

void setup()
{
  boot_splash ();
  Serial.begin (9600);

#ifdef HC_SRF04
  hc_srf04_init ();
#endif

}

void loop()
{
  float dist;
  dist = distance ();
  Serial.print ("Distance(CM): ");
  Serial.println (dist);
  /*
  if ((dist > 5000) || (dist == 0))
    {
      delay (50);
      return;
    }
  */
  buzz ((sqrt ((unsigned int)dist)));
  //  delay (2000);
}
