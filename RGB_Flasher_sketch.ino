/*
RGB Flasher
Flashes the red, green, and blue LEDs of a RGB LED
Turns on an LED on for one second, then off for one second for each
color LED.
15 Feb 2013
Don Wilcher
*/

// RGB pins wired to the Arduino microcontroller.
// give them names:
int redled = 9;
int grnled = 10;
int bluled = 11;

// the setup routine runs once when you press reset:

void setup() {
// initialize the digital pins as outputs:
pinMode(redled, OUTPUT);
pinMode(grnled, OUTPUT);
pinMode(bluled, OUTPUT);
// turn RGB outputs off:
digitalWrite(redled, HIGH);
digitalWrite(grnled, HIGH);
digitalWrite(bluled, HIGH);
}

// the loop routine runs over and over again forever:

void loop() {
digitalWrite(redled, LOW); // turn the red LED on
delay(1000); // wait for a second
digitalWrite(redled, HIGH); // turn the LED off
delay(1000); // wait for a second
digitalWrite(grnled, LOW); // turn the green LED on
delay(1000); // wait for a second
digitalWrite(grnled, HIGH); // turn the green LED off
delay(1000); // wait for a second
digitalWrite(bluled, LOW); // turn the blue LED on
delay(1000); // wait for a second
digitalWrite(bluled, HIGH); // turn the blue LED off
delay(1000); // wait for a second
}