/* This sketch controls a servo motor using a tilt control switch!
* Serial Monitor displays digital data from Tilt Control Switch.
*
* by Don Wilcher 15 December 2012
*
*/
#include<Servo.h> // include Servo library
int inPin = 2; // the Arduino input pin tilt control switch is wired to D2
int reading; // the current reading from the input pin
Servo myservo; // create servo motor object
void setup()
{
myservo.attach(9); // attach servo motor to pin 9 of Arduino
pinMode(inPin, INPUT); // make pin 2 an input
Serial.begin(9600); // open communication port
}
void loop()
{
reading = digitalRead(inPin); // store digital data in variable
if(reading == HIGH) { // check it against target value (HIGH)
myservo.write(90); // if digital data equals target value,
// servo motor rotates 90 degrees
Serial.println(reading); // print tilt control switch digital data
delay(15); // wait 15ms for rotation
}
else { // if it's not equal to target value...
myservo.write(0); // rotate servo motor to 0 degrees
Serial.println(reading); // print tilt control switch digital data
delay(15); // wait 15ms for rotation
}
}