#include <Servo.h>//Using servo library to control ESC
#define UP 2000
#define DOWN 700
Servo esc; //Creating a servo class with name as esc
int val = 0;
int val_ESC = 0;


void setup() {
  esc.attach(8); //Specify the esc signal pin,Here as D8
  esc.writeMicroseconds(1000); //initialize the signal to 1000
  Serial.begin(9600);
  //Creating a variable val
  esc.writeMicroseconds(UP); //using val as the signal to esc

}

void loop()
{

  if (Serial.available() > 1) {
  esc.writeMicroseconds(DOWN); //using val as the signal to esc
  delay(500);
  esc.writeMicroseconds(UP); //using val as the signal to esc
  delay(1000);
  esc.writeMicroseconds(DOWN);
  }
  

}
