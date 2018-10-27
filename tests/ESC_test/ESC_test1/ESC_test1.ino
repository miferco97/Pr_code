#include <Servo.h>//Using servo library to control ESC

Servo esc; //Creating a servo class with name as esc
float val = 0;
float val_ESC = 0;
float Speed = 0;

void setup() {
  esc.attach(8); //Specify the esc signal pin,Here as D8
  esc.writeMicroseconds(1000); //initialize the signal to 1000
  Serial.begin(9600);
  //Creating a variable val
}

void loop()
{
  if (Serial.available() > 1) {
    Speed = Serial.parseInt();
    Serial.println(Speed);
    // val = map(val, 0, 1023, 1000, 2000); //mapping val to minimum and maximum(Change if needed)


  }

  if (Speed != val) {
    if (Speed == 0) val=0;
    else if (Speed >= val) {
      val += 0.05;
    }
    else {
      val += -0.05;
    }
    val_ESC = map(val, 0, 100, 780, 2000);
  }

  esc.writeMicroseconds(val_ESC); //using val as the signal to esc
  Serial.println(val_ESC);


}
