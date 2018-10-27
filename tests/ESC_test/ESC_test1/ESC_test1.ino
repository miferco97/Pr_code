#include <Servo.h>//Using servo library to control ESC

Servo esc; //Creating a servo class with name as esc
int val =0;

void setup() {
  esc.attach(8); //Specify the esc signal pin,Here as D8
  esc.writeMicroseconds(1000); //initialize the signal to 1000
  Serial.begin(9600);
   //Creating a variable val
}

void loop()
{
  if (Serial.available() > 1) {
    val=Serial.parseInt();
    Serial.println(val);
    //val = map(val, 0, 1023, 1000, 2000);
    
    val = map(val, 0, 100, 780, 2000);
     
  }  
 // val = map(val, 0, 1023, 1000, 2000); //mapping val to minimum and maximum(Change if needed)
  esc.writeMicroseconds(val); //using val as the signal to esc
  Serial.println(val);
  
  
}
