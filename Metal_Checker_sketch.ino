/*
Metal Checker
Turns on and off a piezo buzzer at pin 7 when metal is placed across
the sense wires of the metal sensor circuit attached to pin 6.
The circuit:
* Piezo buzzer attached from pin 7 to ground
* Metal Checker sensor attached to pin 7
* 1K? fixed resistor attached from pin 6 to ground
March 2013
by Don Wilcher
*/
// set pin numbers:
const int MSensePin = 6; // the number of the metal sense pin
const int PBuzzerPin = 7; // the number of the piezo buzzer pin
// variables will change:
int MetalStatus = 0; // variable for the metal sense status
void setup() {
// initialize the LED pin as an output:
pinMode(PBuzzerPin, OUTPUT);
// initialize the pushbutton pin as an input:
pinMode(MSensePin, INPUT);
}
void loop(){
// read the state of the metal sense value:
MetalStatus = digitalRead(MSensePin);
// check if metal is present
// if it is, the MetalStatus is HIGH:
if (MetalStatus == HIGH) {
// turn piezo buzzer on:
digitalWrite(PBuzzerPin, HIGH);
}
else {
// turn MetalStatus off:
digitalWrite(PBuzzerPin, LOW);
}
}