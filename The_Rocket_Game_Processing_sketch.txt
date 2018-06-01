/*
* The Rocket Game
*
* Reads the values which represent the state of 4 switches
* from the serial port and draws a graphical representation.
* Sketch inspired by Melvin Ochsmann's Multiple8 Switches
*
* 05 June 2013 modified by Don Wilcher
*/
// importing the processing serial class
import processing.serial.*;
// the display item draws the background and grid
DisplayItems di;
// definition of window size and framerate
int xWidth = 512;
int yHeight = 512;
int fr = 12;
// attributes of the display
boolean bck = true;
boolean grid = true;
boolean g_vert = false;
boolean g_horiz = true;
boolean g_values = true;
boolean output = true;
// variables for serial connection, port name, and baud rate have to be set
Serial port;
// establish serial port connection
// The "2" corresponds to the 3rd port (counting from 0) on the Serial
// Port list dropdown. You might need to change the 2 to something else.
String portname =Serial.list()[2];
int baudrate = 9600;
int value = 0;
// variables to draw graphics
int i;
// if you would like to change fonts, make sure the font file (which
// can be created with Processing) is in the data directory
String fontname2 = "Helvetica-Bold-96.vlw";
int fontsize2 = 72; // change size of text on screen
PFont font2;
float valBuf[] = new float[8];
int xpos, ypos;
// lets user control DisplayItems properties and value output in console
void keyPressed(){
if (key == 'b' || key == 'B') bck=!bck; // background black/white
if (key == 'g' || key == 'G') grid=!grid; // grid ON/OFF
if (key == 'v' || key == 'V') g_values=!g_values; // grid values ON/OFF
if (key == 'o' || key == 'O') output=!output; //turns value output ON/OFF
}
void setup(){
// set size and framerate
size(xWidth, yHeight); frameRate(fr);
// establish serial port connection
port = new Serial(this, portname, baudrate);
println(port);
// create DisplayItems object
di = new DisplayItems();
// load second font for graphical representation and clear value buffer
font2 = loadFont(fontname2);
for(i = 0; i < valBuf.length; i++ ){
valBuf[i] = (height/2);
}
}
void drawFourSwitchesState(){
textFont(font2, fontsize2);
if (output) print("4Switches Statuses: ");
// takes value, interprets it as a byte
// and reads each bit
for (i=0; i < 4 ; i++){
if(output) print(value & 1);
print("ROCKET!!");
// if a bit is 1 increase the corresponding value in value buffer
// array by 1
if ( (value & 1) == 1){ // if 0, number drops when pushbutton is
// pressed; if 1, number goes up when
// pushbutton is pressed
if(valBuf[i] > fontsize2 ) valBuf[i] -=1;
// if a bit is 0 decrease corresponding value
}else{
if(valBuf[i] < height) valBuf[i] += 1;
}
if(output)
print(".");
// draw number for each value at its current height
fill( ( (i%3==0) ? 255 : 0 ),
( (i%3==1) ? 255 : 0 ) ,
( (i%3==2) ? 255 : 0 ));
text( ( "ROCKET"+(i+1) ),
(i*(width/12)) + (width/15),
valBuf[i]); // prints "ROCKET" along with number
value = value >> 1;
} // end for loop
if(output)
println("");
}
void draw(){
// listen to serial port and set value
while(port.available() > 0){
value = port.read();
}
// draw background, then four switches and finally rest of DisplayItems
di.drawBack();
drawFourSwitchesState();
di.drawItems();
}