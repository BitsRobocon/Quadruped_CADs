/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald 
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo kservo;

Servo hservo;
// create servo object to control a servo
// twelve servo objects can be created on most boards

    // variable to store the servo position

void setup() {
  kservo.attach(8); 
  hservo.attach(9);// attaches the servo on pin 9 to the servo object
}

void loop() {
  //for (pos = 30; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    kservo.write(180);
    hservo.write(130);// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
 // }
  /*for (pos = 140; pos >= 30; pos -= 1) { // goes from 180 degrees to 0 degrees
    kservo.write(pos);
    hservo.write(pos);
    // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }*/
}

