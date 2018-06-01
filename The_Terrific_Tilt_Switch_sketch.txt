/*
* The Terrific Tilt Switch
*
* Reads a digital input from a tilt switch and sends a series of
* L's or H's to the Serial Monitor.
*
*
*/
// variables for input pin and control LED
int digitalInput = 7;
int LEDpin = 13;
// variable to store the value
int value = 0;
void setup(){
// declaration pin modes
pinMode(digitalInput, INPUT);
pinMode(LEDpin, OUTPUT);
// begin sending over serial port
Serial.begin(9600);
}

void loop(){
// read the value on digital input
value = digitalRead(digitalInput);
// write this value to the control LED pin
digitalWrite(LEDpin, value);
// if value is high then send the letter 'H' else send 'L' for low
if (value) Serial.print('H');
else
Serial.print('L');
// wait a bit to not overload the port
delay(10);
}