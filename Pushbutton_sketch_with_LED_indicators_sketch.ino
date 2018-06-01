// constants won't change; they're used here to
// set pin numbers:
const int buttonPin = 2; // the number of the pushbutton pin
const int ledPin = 12; // the number of the LED pin
const int ledPin13 = 13; // onboard LED

void setup() {
// initialize the LED pins as outputs:
pinMode(ledPin, OUTPUT);
pinMode(ledPin13, OUTPUT);
// initialize the pushbutton pin as an input:
pinMode(buttonPin, INPUT);
}

void loop(){
// read the state of the pushbutton value:
int buttonStatus;
buttonStatus = digitalRead(buttonPin);
// check if the pushbutton is pressed
// if it is, the buttonStatus is HIGH:
if (buttonStatus == HIGH) {
// turn LED on:
digitalWrite(ledPin, HIGH);
// turn off onboard LED:
digitalWrite(ledPin13,LOW);
}
else {
// turn LED off:
digitalWrite(ledPin, LOW);
// turn on onboard LED:
digitalWrite(ledPin13, HIGH);
}
}