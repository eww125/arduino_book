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
// initialize serial communications at 9600 bps:
Serial.begin(9600); // Add code instruction here!
}

void loop(){
// read the state of the light sensor value:
sensorState = digitalRead(lightsensorPin);
// check if the light sensor is activated
// if it is, the sensorState is HIGH:
if (sensorState == HIGH) {
// turn red LED on:
digitalWrite(redledPin, HIGH);
// turn off onboard LED and green LED:
digitalWrite(greenledPin13, LOW);
// display message
Serial.println("Sunset\n"); // Add code instruction here!
}
else {
// turn red LED off:
digitalWrite(redledPin, LOW);
// turn on onboard LED and green LED;
digitalWrite(greenledPin13,HIGH);
// display message
Serial.println("Sunrise\n"); // Add code instruction here!
}
}