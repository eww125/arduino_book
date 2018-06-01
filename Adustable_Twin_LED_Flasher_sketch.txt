/*
Adjustable Twin LED Flasher
Two LEDs will flash at a specified rate
based on the 10K potentiometer setting.
01 Jan 2013
by Don Wilcher
*/
// Two LEDs with 330 ohm series resistors wired
// in parallel connected to pin 9.
int led = 9; // pin D9 assigned to led variable.
// A 10K potentiometer center pin wired to pin A0.
// One pin is wired to +5V with the other connected to GND.
int PotIn = A0; // pin A0 assigned to PotIn variable.
int Flash; // Flash variable to be used with "delay" instruction.
// the setup routine runs once when you press reset:

void setup() {
// initialize the digital pin as an output:
pinMode(led, OUTPUT);
// initialize the analog pin as an input:
pinMode(PotIn, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
Flash =analogRead(PotIn); // read 10K pot, store value in Flash variable
digitalWrite(led, HIGH); // turn the LED on (HIGH voltage level = on)
delay(Flash); // wait for a Flash time delay in seconds
digitalWrite(led, LOW); // turn the LED off by making the voltage LOW
delay(Flash); // wait for a Flash time delay in seconds
}