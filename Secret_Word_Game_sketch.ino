/*
Demonstrates the use of a 16x2 LCD. Momentary press of the Start Game
pushbutton will turn on the RGB LED timing sequencing. The RGB LED turns
off and the secret word can be revealed by a shining light on a photocell.
25 August 2013
by Don Wilcher
*/
// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buttonPin = 6; // the number of the Start Game pushbutton pin
int RPin = 7; // select the pin for the red LED
int GPin = 8; // select the pin for the green LED
int BPin = 9; // select the pin for the blue LED
// variables will change:
int buttonStatus = 0; // variable for reading the Start Game
// pushbutton status
void setup() {
// initialize the pushbutton pin as an input:
pinMode(buttonPin, INPUT);
// declare the LED pins as outputs:
pinMode(RPin, OUTPUT);
pinMode(GPin, OUTPUT);
pinMode(BPin, OUTPUT);
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
}
void loop() {
// read the state of the pushbutton value:
buttonStatus = digitalRead(buttonPin);
// check if the pushbutton is pressed
// if it is, the buttonState is HIGH:
if (buttonStatus == HIGH) {
lcd.clear();
delay(500);
for (int i=0; i <= 5; i++){
lcd.setCursor(8,0);
lcd.print(i);
// turn the red LED on:
digitalWrite(BPin, HIGH);
digitalWrite(RPin, LOW);
// delay red LED for 1/2 second:
delay(500);
// turn the green LED on:
digitalWrite(RPin, HIGH);
digitalWrite(GPin, LOW);
// delay green LED for 1/2 second:
delay(500);
// turn the blue LED on:
digitalWrite(GPin, HIGH);
digitalWrite(BPin, LOW);
//delay blue LED for 1/2 second:
delay(500);
}
} else {
//turn red, green, and blue LEDs off:
digitalWrite(RPin, HIGH);
digitalWrite(GPin, HIGH);
digitalWrite(BPin, HIGH);
// print a Secret Word to the LCD:
lcd.setCursor(0,0);
lcd.print("Secret Word is:");
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(0, 1);
// print the number of seconds since reset:
lcd.print("Cat"); // change secret word or phrase here!!!
}
}