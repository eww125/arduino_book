/*
Logic Tester
LCD displays "HIGH (1)" when digital circuit signal is +5V. A "LOW (0)"
is displayed when digital circuit signal is OV.
27 April 2013
Don Wilcher
*/
// include the LCD library code:

#include <LiquidCrystal.h>
// set up pins on Arduino for LCD and transistor lead:
LiquidCrystal lcd(12,11,5,4,3,2);
int xistorPin = 6;
int digitalStatus = 0; // variable for reading the digital circuit state

// initialize the transistor pin as an input and set up the LCD's number
// of columns and rows:

void setup() {
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("LOGIC TESTER");
pinMode(xistorPin, INPUT);
}

void loop() {
// check if digital signal is HIGH or LOW:
digitalStatus = digitalRead(xistorPin);
if (digitalStatus == HIGH) {
// if digital circuit signal is +5V, display HIGH (1):
lcd.setCursor(0,1);
lcd.print("HIGH (1) "); // display HIGH (1)
}
else {
// if digital circuit signal is 0V, display LOW (0):
lcd.setCursor(0,1);
lcd.print(" LOW (0) ");
}
}