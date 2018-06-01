#include <Servo.h>
Servo myservo; // create servo object to control a servo
// a maximum of eight servo objects can be created
int pos = 0; // variable to store the servo position
void setup()
{
myservo.attach(2); // attaches the servo on pin 2 to the servo object
}
void loop()
{
for(pos = 0; pos < 170; pos += 1) // goes from 0 degrees to 170 degrees
{ // in steps of 1 degree
myservo.write(pos); // move to position in variable 'pos'
delay(15); // waits 15ms to reach the position
}
for(pos = 170; pos>=1; pos-=1) // goes from 170 degrees to 0 degrees
{
myservo.write(pos); // move to position in variable 'pos'
delay(15); // waits 15ms to reach the position
}
}