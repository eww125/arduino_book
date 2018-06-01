/*
Sunrise-Sunset Light Switch
Turns on and off a light-emitting diode (LED) connected to digital
pins 12 and 13 after 10 to 20 seconds, by waving a hand over a photocell
attached to pin 2.
23 Nov 2012
by Don Wilcher
*/

// constants won't change; they're used here to
// set pin numbers:
const int lightsensorPin = 2; // the number of the light sensor pin
const int redledPin = 12; // the number of the red LED pin
const int greenledPin13 = 13; // onboard LED and green LED pin
// variables will change:
int sensorState = 0; // variable for reading light sensor status

void setup() {
// initialize the LED pins as outputs:
pinMode(redledPin, OUTPUT);
pinMode(greenledPin13, OUTPUT);
// initialize the light sensor pin as an input:
pinMode(lightsensorPin, INPUT);
}

void loop(){
// read the state of the pushbutton value:
sensorState = digitalRead(lightsensorPin);
// check if the light sensor is activated
// if it is, the sensorState is HIGH:
if (sensorState == HIGH) {
// turn red LED on:
digitalWrite(redledPin, HIGH);
// turn off onboard LED and green LED:
digitalWrite(greenledPin13, LOW);
}
else {
// turn red LED off:
digitalWrite(redledPin, LOW);
// turn on onboard LED and green LED;
digitalWrite(greenledPin13, HIGH);
}
}