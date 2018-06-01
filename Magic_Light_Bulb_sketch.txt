/*
Magic Light Bulb
Flashes the red, green, and blue LEDs of a RGB LED three times by
momentarily pressing a mini pushbutton switch.
25 Feb 2013
Don Wilcher
*/

// Pushbutton switch and RGB pins wired to the Arduino microcontroller.
// give them names:
int redled = 9;
int grnled = 10;
int bluled = 11;
int Pbutton = 8;
// initialize counter variable
int n =0;
// monitor pushbutton switch status:
int Pbuttonstatus = 0;
// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pins as outputs:
pinMode(redled, OUTPUT);
pinMode(grnled, OUTPUT);
pinMode(bluled, OUTPUT);
// initialize the digital pin as an input:
pinMode(Pbutton, INPUT);

// turn RGB outputs off:
digitalWrite(redled, HIGH);
digitalWrite(grnled, HIGH);
digitalWrite(bluled, HIGH);
}

// the loop routine runs 3x after the pushbutton is pressed:
void loop() {
Pbuttonstatus = digitalRead(Pbutton); // read pushbutton status
if(Pbuttonstatus == HIGH) { // if it's HIGH, start RGB Flasher
for (n = 0; n < 3; n++){ // flash RGB LEDs 3x
digitalWrite(redled, LOW); // turn the red LED on (LOW is on)
delay(250); // wait for a 1/4 second
digitalWrite(redled, HIGH); // turn the LED off (HIGH is off)
delay(250); // wait for a 1/4 second
digitalWrite(grnled, LOW); // turn the green LED on
delay(250); // wait for a 1/4 second
digitalWrite(grnled, HIGH); // turn the green LED off
delay(250); // wait for a 1/4 second
digitalWrite(bluled, LOW); // turn the blue LED on
delay(250); // wait for a 1/4 second
digitalWrite(bluled, HIGH); // turn the blue LED off
delay(250); // wait for a 1/4 second
}
}
else{ // if pushbutton is LOW, turn LEDs off
digitalWrite(redled, HIGH);
digitalWrite(grnled, HIGH);
digitalWrite(bluled, HIGH);
}
}