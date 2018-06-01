/*
Electronic Pixel
An example of using an Arduino microcontroller for serial communication to
receive binary data from a computer. In this case, the Arduino boards
turns on an RGB LED when it receives the 'H' character, and turns off
the RGB LED when it receives the 'L' character. Also, an electrical
switch can change the colors of the RGB LED between green and red.
The on and off command data can be sent from the Arduino
Serial Monitor.
*/
int ledPin = 9; // the pin that the RGB LED is attached to
int incomingByte; // a variable to read incoming serial data
void setup() {
// initialize serial communication:
Serial.begin(9600);
// initialize the RGB LED pin as an output:
pinMode(ledPin, OUTPUT);
}
void loop() {
// see if there's incoming serial data:
if (Serial.available() > 0) {
// read the oldest byte in the serial buffer:
incomingByte = Serial.read();
// if it's a capital H, turn on the LED:
if (incomingByte == 'H') {
digitalWrite(ledPin, LOW);
}
// if it's an L, turn off the LED:
if (incomingByte == 'L') {
digitalWrite(ledPin, HIGH);
}
}
}