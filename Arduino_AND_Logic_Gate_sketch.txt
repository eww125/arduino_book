/*
The Arduino AND Logic Gate
Turns on an LED connected to digital
pin 7, when pressing a pushbutton switch and covering a photocell
attached to pins 3 and 4.
27 Jan 2013
Revised 4 September 2013
by Don Wilcher
*/
// constants won't change; they're used here to
// set pin numbers:
int B = 3; // the number of the B pushbutton pin
int A = 4; // the number of the A pushbutton pin
const int Cout = 7; // the number of the LED pin
// variables will change:
int AStatus = 0; // variable for reading the A pushbutton status
int BStatus = 0;
void setup() {
// initialize the LED pin as an output:
pinMode(Cout, OUTPUT);
// initialize the pushbutton pins as inputs:
pinMode(B, INPUT);
pinMode(A, INPUT);
}
void loop(){
// read the state of the pushbutton value:
AStatus = digitalRead(A);
BStatus = digitalRead(B);
// check if the pushbuttons are pressed
// if it is, the buttonStatus is HIGH:
if (AStatus == HIGH && BStatus ==HIGH) {
// turn LED on:
digitalWrite(Cout, HIGH);
}
else {
// turn LED off:
digitalWrite(Cout, LOW);
}
}