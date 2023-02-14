#pragma config(Sensor, S1,     MSLSA,          sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
 * mindsensors-lineleader.h provides an API for the Mindsensors LineLeader Sensor.  This program
 * demonstrates how to use that API.
 *
 * Changelog:
 * - 0.1: Initial release
 * - 0.2: More comments
 *
 * Credits:
 * - Big thanks to Mindsensors for providing me with the hardware necessary to write and test this.
 *
 * License: You may use this code as you wish, provided you give credit where it's due.
 *
 * THIS CODE WILL ONLY WORK WITH ROBOTC VERSION 4.10 AND HIGHER

 * Xander Soldaat (xander_at_botbench.com)
 * 28 November 2009
 * version 0.2
 */

#include "mindsensors-lightsensorarray.h"

task main {
  tIntArray signalstr;

  MSLSAinit(MSLSA);

  while (true) {
    // Fetch all of the uncalibrated sensor values and display them
    if (!MSLSAreadRawSensors(MSLSA, &signalstr[0]))
    {
      eraseDisplay();
      playSound(soundException);
      displayCenteredTextLine(4, "error!");
      sleep(5000);
    }
    for (short i = 0; i < 8; i++) {
      displayTextLine(i, "S[%d]: %d", i, signalstr[i]);
    }
    sleep(50);
  }
}
