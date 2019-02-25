/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

#define ohmac1  90               //actual (physical) angle of femur with vertical at a particular time
#define ohmmot1 180                //value fed to motor (pos) for that femur angle
#define ohmac2 -90
#define ohmmot2 15

#define thetaac1 180               //actual (physical) angle of tibia with femur at a particular time
#define thetaac2 0             //value fed to motor (pos) for that tibia angle
#define thetamot1 20
#define thetamot2 180


#define femur_length 18.5           // in cm
#define tibia_length 17            
#define h 25.1               // height of hip in cm

Servo hservo;  // create servo object to control a servo
Servo kservo;// twelve servo objects can be created on most boards


float find_ohm(float x, float y){              ////finds physical ohm for a given combination of x and y

  float magsquare= (pow((h-y),2)+pow(x,2));    // square of magnitude of the location of point wrt origin 
  float a= (pow((h-y),2)+pow(x,2)+pow(femur_length,2)-pow(tibia_length,2))/(2*femur_length*(pow(magsquare,0.5)));
  float b= (h-y)/pow(magsquare, 0.5);
  float angle = asin(a)-asin(b);
  return angle;
}            

float find_motor_ohm(float ohm_ac){              ////finds the motor pos of ohm for a given physical ohm
  float motor_ohm= ((ohmmot2-ohmmot1)/(ohmac2-ohmac1))*ohm_ac+ ohmac1;
  return motor_ohm;
}




float f(float x){ 
  float y = pow((36-pow(x,2)),0.5);                                 ///// define fx
  return y;
}

void setup() {
  hservo.attach(8);
  kservo.attach(9);// attaches the servo on pin 9 to the servo object
}

float complete_loop() {
  float x=6;
  float y = (f(x));
  float   ohmac= find_ohm(x,y);
  //float   thetaac= find_theta(x, ohmac);         /////// give the output to the servos
  //kservo.write(find_motor_theta(thetaac));
  hservo.write(180);
  delay(100);
  for (x=6; (x>-5.9);x-=0.1){  ////define the conditions
    y = f(x);
    float   ohmac= find_ohm(x,y);
    //float   thetaac= find_theta(x, ohmac);         /////// give the output to the servos
    //kservo.write(find_motor_theta(thetaac));
    hservo.write(180);
    delay(50);
  }
  for (x=-6; (x<5.9) ; x+=0.1){     /////////////define the conditions
    y=f(x);
    float   ohmac= find_ohm(x,y);
    //float   thetaac= find_theta(x, ohmac);
    //kservo.write(find_motor_theta(thetaac));
    hservo.write(15);
    delay(50);
  }
}

void loop(){
  complete_loop();
}
