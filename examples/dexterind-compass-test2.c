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
 * 14 March 2012
 * version 0.1
 */

#include "dexterind-compass.h"

task main(){

  // This struct holds all the sensor related data
  tDIMC compass;
	tSensors DIMC = S1;

  displayCenteredTextLine(0, "Dexter Ind.");
  displayCenteredBigTextLine(1, "dCompass");
  displayCenteredTextLine(3, "Test 2");
  displayCenteredTextLine(5, "Connect sensor");
  displayCenteredTextLine(6, "to S1");
  sleep(2000);
  eraseDisplay();

  // Fire up the compass and initialize it. Only needs to be done once.
  if (!initSensor(&compass, DIMC))
    playSound(soundException);

  // This program uses an omniwheel platform to rotate the robot about
  // its axis a few times but you can use another robot to do this.
  // Just make sure the robot rotates around 2-3 times about is axis
  startCal(&compass);

  displayCenteredTextLine(1, "Calibrating...");
  displayCenteredTextLine(2, "Turn the sensor");
  displayCenteredTextLine(3, "slowly");

  time1[T1] = 0;
  while(time1[T1] < 15000)
  {
    // Read the Compass
    if (!readSensor(&compass))
      playSound(soundException);

    if (time1[T1] % 1000 < 10)
      displayCenteredBigTextLine(5, "%d", 15 - (time1[T1]/1000));

  }

  // Stop the calibration and store the data
  stopCal(&compass);

  eraseDisplay();
  sleep(100);
  while (true){

    // Read the Compass
    if (!readSensor(&compass))
      playSound(soundException);

    displayCenteredBigTextLine(1, "Heading");
    displayCenteredBigTextLine(3, "%3.2f", compass.heading);
    displayTextLine(5, "%d", compass.axes[0]);
    displayTextLine(6, "%d", compass.axes[1]);
    displayTextLine(7, "%d", compass.axes[2]);
    sleep(50);
  }
}
