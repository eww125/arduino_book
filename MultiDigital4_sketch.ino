/*
* MultiDigital4
*
* Reads 8 digital inputs and sends their values over the serial port.
* A byte variable is used to store the state of all eight pins. This byte
* is then sent over the serial port.
*
* modified ap_ReadDigital8 sketch by Melving Oschmann
*
* 8 June 2013 Don Wilcher
*
*/
// 8 variables for each pin
int digitalInput_1 = 3;
int digitalInput_2 = 4;
int digitalInput_3 = 5;
int digitalInput_4 = 6;
int digitalInput_5 = 7;
int digitalInput_6 = 8;
int digitalInput_7 = 9;
int digitalInput_8 = 10;
// 8 variables to store the values
int value_1 = 0;
int value_2 = 0;
int value_3 = 0;
int value_4 = 0;
int value_5 = 0;
int value_6 = 0;
int value_7 = 0;
int value_8 = 0;
// byte variable to send state of all pins over serial port
int myByte = 0;
// control LED
int controlLED = 13;
void setup(){
// set pin modes
pinMode(digitalInput_1, INPUT); pinMode(digitalInput_2, INPUT);
pinMode(digitalInput_3, INPUT); pinMode(digitalInput_4, INPUT);
pinMode(digitalInput_5, INPUT); pinMode(digitalInput_6, INPUT);
pinMode(digitalInput_7, INPUT); pinMode(digitalInput_8, INPUT);
pinMode(controlLED, OUTPUT);
// begin sending out over the serial port
Serial.begin(9600);
}
void loop(){
// set 'myByte' to zero
myByte = 0;
// then read all the INPUTS and store values
// in the corresponding variables
value_1 = digitalRead(digitalInput_1);
value_2 = digitalRead(digitalInput_2);
value_3 = digitalRead(digitalInput_3);
value_4 = digitalRead(digitalInput_4);
value_5 = digitalRead(digitalInput_5);
value_6 = digitalRead(digitalInput_6);
value_7 = digitalRead(digitalInput_7);
value_8 = digitalRead(digitalInput_8);
/* check if values are high or low and 'add' each value to myByte
* what it actually does is this:
*
* 00 00 00 00 ('myByte set to zero')
* | 00 10 10 00 ('3 and 5 are 1')
* --------------
* 00 10 10 00 ('myByte after logical operation')
*
*/
if (value_1) {
myByte = myByte | 0;
digitalWrite(controlLED, HIGH);
} else digitalWrite(controlLED, LOW);
if (value_2) { myByte = myByte | 1; }
if (value_3) { myByte = myByte | 2; }
if (value_4) { myByte = myByte | 4; }
if (value_5) { myByte = myByte | 8; }
if (value_6) { myByte = myByte | 16; }
if (value_7) { myByte = myByte | 32; }
if (value_8) { myByte = myByte | 64; }
// send myByte out over serial port and wait a bit to not overload the port
Serial.print(myByte);
delay(10);
}
