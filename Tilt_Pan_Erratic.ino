#include <Servo.h>

Servo spin;    // create servo object for spin (bottom)
Servo tilt;  // create servo object to tilt (bottom)
Servo spin2; //upper spin servo
Servo tilt2; // tilt2 servo

long noise;

void setup() {
  Serial.begin(9600);
  Serial.println("");
  spin.attach(9);   // attaches spin servo on pin 9 to the servo object
  tilt.attach(7);  // attaches tilt servo on pin 7 to the servo object
  spin2.attach(5);  // attaches spin2 servo on pin 5 to the servo object
  tilt2.attach(11); // attaches tilt2 servo on pin 11 to the servo object 
}

void loop() {

  
//  Move both servos at the same time(ish) 
  int smin=1;  //right
  int smax=179; //left
  int spos=0;  //current position
  int sinc=1;   //movement increment in degrees

  int tmin=81;  //top
  int tmax=120; //bot
  int tpos=80;  //current position
  int tinc=1;   //movement increment in degrees

  int t2min=91;  //top
  int t2max=130; //bot
  int t2pos=90;  //current position
  int t2inc=1;   //movement increment in degrees

   
  Serial.println("Huzza");
  for(int i=0; i<18000; i++) {

     noise = random(-10,10);
    Serial.println(noise);

    spos += sinc+noise;                           //increment
    if(spos > smax) {spos=smax; sinc = -1;} //check for limit, change direction if necessary
    if(spos < smin) {spos=smin; sinc = 1;}  //check for limit, change direction if necessary
  
    tpos += tinc+noise;                           //increment 
// if(tpos < tmin && spos < 60 || spos > 120) {tpos=tmin; tinc = 1;}  //check for limit, change direction if necessary
   if(tpos < tmin && spos > tmax) {tpos=tmin; tinc = 1;}  //check for if spos greater than 120 and tpos less than 81
   if(tpos < tmin && spos < 60) {tpos=tmin; tinc = 1;}  //check for limit, change direction if necessary 
   if(tpos > tmax) {tpos=tmax; tinc = -1;} //check for limit, change direction if necessary

  t2pos += t2inc+noise;                           //increment
    if(t2pos > t2max) {t2pos=t2max; t2inc = -1;} //check for limit, change direction if necessary
    if(t2pos < t2min) {t2pos=t2min; t2inc = 1;}  //check for limit, change direction if necessary
 

    spin.write(spos);  //move spin servo
    delay(20);
    spin2.write(spos); // spin2
    delay(20);
    tilt.write(tpos); //move tilt servo
    delay(20);
    tilt2.write(t2pos);
    delay(20 );        //some delay
  }
}
