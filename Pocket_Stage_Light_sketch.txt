/*
Pocket Stage Light
The RGB LED will sequence in colors (blue, green, red) by use
of a thermistor.
15 August 2013
by Don Wilcher
*/
int tsensorPin = A0; // select the input pin for the temperature sensor
int RPin = 11; // select the pin for the red LED
int GPin = 10; // select the pin for the green LED
int BPin = 9; // select the pin for the blue LED
int tsensorValue = 0; // to store the value from the temperature sensor
void setup() {
// declare the LED pins as outputs:
pinMode(RPin, OUTPUT);
pinMode(GPin, OUTPUT);
pinMode(BPin, OUTPUT);
Serial.begin(9600);
}
void loop() {
// read the value from the sensor:
tsensorValue = analogRead(tsensorPin);
Serial.println(tsensorValue);
delay(100);
if (tsensorValue > 190){
// turn the blue LED on:
digitalWrite(BPin, LOW);
digitalWrite(RPin, HIGH);
// delay blue LED for 5 seconds:
delay(5000);
// turn the green LED on:
digitalWrite(BPin, HIGH);
digitalWrite(GPin, LOW);
// delay green LED for 5 seconds:
delay(5000);
// turn the red LED on:
digitalWrite(GPin, HIGH);
digitalWrite(RPin, LOW);
//delay red LED for 5 seconds:
delay(5000);
}
else{
// turn blue, green, and red LEDs off:
digitalWrite(BPin, HIGH);
digitalWrite(GPin, HIGH);
digitalWrite(RPin, HIGH);
}
}