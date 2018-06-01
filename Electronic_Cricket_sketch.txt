/*
Electronic Cricket
Plays a pitch that changes based on a changing analog (temperature) input
*/
int expectedMax = 859;
int expectedMin = 330;
float fahrenheit = 0.0;
void setup() {
// initialize serial communications (for debugging only):
Serial.begin(9600);
}
void loop() {
// read the sensor:
int sensorReading = analogRead(A0);
// print the sensor reading so you know its range
Serial.println(sensorReading);
// map the sensor analog input range
// to the output pitch range (10 - 100Hz)
// change the minimum and maximum input numbers below
// depending on the range your sensor's giving:
int thisPitch = map(sensorReading, expectedMin, expectedMax, 10, 100);
int thisTemperature =
map(sensorReading, expectedMin, expectedMax, -10, 40);
fahrenheit = (5.0/9.0) * (thisTemperature + 32);
Serial.println(fahrenheit);
// play the pitch twice, to imitate a cricket:
tone(9, thisPitch, 10);
// the delay is proportional to the temperature
// (faster chirps mean higher temperatures)
delay(60000/(fahrenheit * 1000));
tone(9, thisPitch, 10);
delay(1); // delay in between reads for stability
}