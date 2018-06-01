/*
Metronome sketch
The servo motor arm will swing back and forth with a tick sound coming
from a piezo buzzer.
31 August 2013
by Don Wilcher
*/
#include <Servo.h>
Servo myservo; // create servo object to control a servo
// a maximum of eight servo objects can be created
int pos = 0; // variable to store the servo position
int PBuzzer = 7; // piezo buzzer pin number
void setup()
{
myservo.attach(9); // attaches the servo on pin 9 to the servo object
pinMode(PBuzzer, OUTPUT);
}
void loop()
{
for(pos = 0; pos <=45; pos += 1) // goes from 0 degrees to 45 degrees
{ // in steps of 1 degree
if(pos==45){
digitalWrite(PBuzzer, LOW);
delay(15);
digitalWrite(PBuzzer, HIGH);
delay(15);
digitalWrite(PBuzzer, LOW);
delay(15);
}
myservo.write(pos); // go to position in variable 'pos'
delay(15); // waits 15ms to reach the position
}
for(pos = 45; pos>=1; pos-=1) // goes from 45 degrees to 0 degrees
{
if (pos==1){
digitalWrite(PBuzzer, LOW);
delay(15);
digitalWrite(PBuzzer, HIGH);
delay(15);
digitalWrite(PBuzzer, LOW);
delay(15);
}
myservo.write(pos); // go to position in variable 'pos'
delay(15); // waits 15ms to reach the position
}
}