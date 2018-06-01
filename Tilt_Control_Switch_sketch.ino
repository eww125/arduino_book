/* This sketch controls a servo motor using a tilt control switch!
*
* by Don Wilcher 12 December 2012
*
*/

#include<Servo.h> // include Servo library
int inPin = 2; // the tilt control switch is wired to Arduino D2 pin
int reading; // the current reading from the input pin
Servo myservo; // create servo motor object

void setup()
{
myservo.attach(9); // attach servo motor to pin 9 of Arduino
pinMode(inPin, INPUT); // make pin 2 an input
}

void loop()
{
reading = digitalRead(inPin); // store digital data in variable
if(reading == HIGH) { // check digital data with target value
myservo.write(180); // if digital data equals target value,
// servo motor rotates 180 degrees
delay(15); // wait 15ms for rotation
}
else { // if reading's not equal to target value,
myservo.write(0); // rotate servo motor to 0 degrees
delay(15); // wait 15ms for rotation
}
}