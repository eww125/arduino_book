/*
Arduino_NOT_Logic_Gate
This sketch demonstrates the NOT(Inverter) Logic Gate operation.
With the pushbutton switch not pressed (Logic LOW input), the green LED
(Logic HIGH output indicator) is on and the red LED (Logic LOW output
indicator) is off.
Pressing the pushbutton turns the green LED off and the red LED on.
11 September 2013
by Don Wilcher
*/
// set pin numbers:
int buttonPin = 2; // the number of the pushbutton pin
int LEDred = 8; // pin number for the red LED
int LEDgreen = 9; // pin number for the green LED

// variables will change:
int buttonStatus = 0; // variable for reading the pushbutton status

void setup() {
// initialize the LED pins as outputs:
pinMode(LEDred, OUTPUT);
pinMode(LEDgreen, OUTPUT);
// initialize the pushbutton pin as an input:
pinMode(buttonPin, INPUT);
}

void loop(){
// read the status of the pushbutton value:
buttonStatus = digitalRead(buttonPin);
// check if the pushbutton is not pressed
//
if (buttonStatus != HIGH) {
// turn green LED on:
digitalWrite(LEDgreen, HIGH);
// turn red LED off:
digitalWrite(LEDred, LOW);
}
else {
// turn green LED off:
digitalWrite(LEDgreen, LOW);
// turn red LED ON:
digitalWrite(LEDred, HIGH);
}
}