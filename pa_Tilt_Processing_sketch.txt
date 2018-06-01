/*
* pa_Tilt
*
* Reads the values which represent the state of a Tilt switch
* from the serial port and draws white-filled circle with vertical lines.
* created 2005 by Melvin Ochsmann for Malmo University
*
*/
import processing.serial.*;
DisplayItems di;
int xWidth = 512;
int yHeight = 512;
int fr = 24;

boolean bck = true;
boolean grid = true;
boolean g_vert = true;
boolean g_horiz = false;
boolean g_values = false;
boolean output = true;
Serial port;
// The "2" corresponds to the 3rd port (counting from 0) on the Serial
// Port list dropdown. You might need to change the 2 to something else.
String portname = Serial.list()[2];
int baudrate = 9600;
int value = 0;
boolean tilted = true;
float a = 0;
int speed = 5; // how many pixels that the circle will move per frame
void keyPressed(){
if (key == 'b' || key == 'B') bck=!bck;
if (key == 'g' || key == 'G') grid=!grid;
if (key == 'v' || key == 'V') g_values=!g_values;
if (key == 'o' || key == 'O') output=!output;
}
void setup(){
size(xWidth, yHeight);
frameRate(fr);
di = new DisplayItems();
port = new Serial(this, portname, baudrate);
println(port);
}
// Method moves the circle from one side to another,
// keeping within the frame
void moveCircle(){
if(tilted) {
background(0);
a = a + speed;
if (a > (width-50)) {
a = (width-50);
}
ellipse(a, (width/2), 100,100);
}else{
background(0);
a = a - speed;
if (a < 50) {
a = 50;
}
ellipse(a, (width/2), 100,100);
}
}
void serialEvent(int serial){
if(serial=='H') {
tilted = true;
if(output) println("High");
}else {
tilted = false;
if(output) println("Low");
}
}
void draw(){
while(port.available() > 0){
value = port.read();
serialEvent(value);
}
di.drawBack();
moveCircle();
di.drawItems();
}