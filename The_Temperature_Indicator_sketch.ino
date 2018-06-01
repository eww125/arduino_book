/*
* Temperature_Indicator
*
* Reads an analog input from the input pin and sends the value
* followed by a line break over the serial port. Data can be viewed
* using the Serial Monitor.
*
* This file is part of the Arduino meets Processing Project:
* For more information visit http://www.arduino.cc.
*
* created 2005 ap_ReadAnalog by Melvin Ochsmann for Malmo University
*
* 10 June 2013 modified by Don Wilcher
*
*/
// variables for input pin and control LED
int analogInput = 3;
int LEDpin = 13;
// variable to store the value
int value = 0;
// a threshold to decide when the LED turns on
int threshold = 800;
void setup(){
// declaration of pin modes
pinMode(analogInput, INPUT);
pinMode(LEDpin, OUTPUT);
// begin sending over serial port
Serial.begin(9600);
}
void loop(){
// read the value on analog input
value = analogRead(analogInput);
// if value greater than threshold turn on LED
if (value < threshold) digitalWrite(LEDpin, HIGH);
else digitalWrite(LEDpin, LOW);
// print out value over the serial port
Serial.println(value);
// and a signal that serves as separator between two values
Serial.write(10);
// wait for a bit to not overload the port
delay(100);
}