import processing.serial.*;
Serial port; // the Serial Port object is created
float val; // variable used to receive thermistor data from Arduino
void setup() {
size(440, 220); // size of canvas
frameRate(30); // how fast the horizontal lines will flutter
smooth(); // reduce jittering of the fluttering horizontal lines
// The "2" corresponds to the 3rd port (counting from 0) on the Serial
// Port list dropdown. You might need to change the 2 to something else.
String portname = Serial.list()[2];
port = new Serial(this, portname, 9600); // baud rate for COM port
background(0); // create a black canvas
}
void draw() {
if (port.available() > 0){ // check for available data on COM port
val= port.read(); // store COM port data in variable "val"
print(val); // print COM data on Console Monitor
// val = map(val, 0, 255, 0, height);
// float targetVal = val;
// easedVal += (targetVal - easedVal)* easing;
}
rect(40, val, 360, 20); // display data has a fluttering horizontal
// line inside a rectangle
}