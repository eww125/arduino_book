/*
Theremin
Plays sound effects through a simple transistor
amplifier using a photocell.
I/O circuits:
* A simple transistor amplifer wired to digital pin 8
* A photocell wired to analog 0 and +5V
* A 10K resistor wired to analog 0 pin to ground
*/
void setup() {
// initialize serial communications (for debugging only):
Serial.begin(9600);
}
void loop() {
// read the sensor:
int sensorReading = analogRead(A0);
// print the sensor reading so you know its range:
Serial.println(sensorReading);
// map the analog input range (in this case, 400 - 1000 from
// the photoresistor) to the output pitch range (120 - 1500Hz)
// change the minimum and maximum input numbers below
// depending on the range your sensor's giving:
int thisPitch = map(sensorReading, 400, 1000, 120, 1500);
// play the pitch:
tone(9, thisPitch, 10);
delay(1); // delay in between reads for stability
}