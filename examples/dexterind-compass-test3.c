/**
 * dexterind-compass.h provides an API for the Dexter Industries dCompass Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 *
 * Credits:
 * - Big thanks to Dexter Industries for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 05 April 2012
 * version 0.1
 */

#include "dexterind-compass.h"

task main ()
{
  // This struct holds all the sensor related data
  tDIMC compass;
	tSensors DIMC = S1;

  // Our local variables
  short strength = 0;

  // Fire up the compass and initialize it. Only needs to be done once.
  if (!initSensor(&compass, DIMC))
    playSound(soundException);

  // Loop forever, reading the sensor and calulating total
  // field strength
  while (true)
  {
    // Read the Compass
    if (!readSensor(&compass))
      playSound(soundException);

    // calculate the field strength
    strength = sqrt(pow(compass.axes[0], 2) + pow(compass.axes[1], 2) + pow(compass.axes[2], 2));

    // Play a tone of the frequency of the field strength
    // Great for annoying the cat/dog/wife/parent
    playImmediateTone(strength, 8);

    // display on the screen
    displayCenteredBigTextLine(3, "%d", strength);
    sleep(50);
  }
}
