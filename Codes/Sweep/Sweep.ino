/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo hservo;  // create servo object to control a servo
Servo kservo;// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  hservo.attach(9);
  kservo.attach(8);// attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 20; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    hservo.write(pos);
    kservo.write(pos);// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 20; pos -= 1) { // goes from 180 degrees to 0 degrees
    hservo.write(pos);
    kservo.write(pos);// tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
