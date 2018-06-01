/*
Up-Down Sensor with Flashing LEDs
Flashes Green and Red LEDs at pin 8
when the tilt control switch attached to pin 3 is tilted. The Green LED
wired to pin 8 turns turns solid when no tilt condition is detected.
05 Feb 2013
Don Wilcher
*/
// constants won't change; they're used here to
// set pin numbers:
const int tiltPin = 3; // the number of the tilt control switch pin
const int ledPin = 8; // the number of the LED pin
// variables will change:
int tiltState = 0; // variable for tilt control switch status
void setup() {
pinMode(ledPin, OUTPUT);
// initialize the tilt control switch pin as an input:
pinMode(tiltPin, INPUT);
}
void loop(){
// read the state of the tilt control switch value:
tiltState = digitalRead(tiltPin);
// check if the tilt control switch contacts are closed
// if they are, the tiltState is HIGH:
if (tiltState == HIGH) {
// turn Red LED on;
digitalWrite(ledPin, HIGH);
// wait 100ms:
delay(100);
// turn LED off:
digitalWrite(ledPin,LOW);
// wait 100ms:
delay(100);
}
else {
// turn LED off:
digitalWrite(ledPin, LOW);
}
}