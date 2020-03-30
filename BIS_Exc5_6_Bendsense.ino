#include <Servo.h>
Servo servo;

/*
red = vcc
black = gnd
orange = signal
*/

int angle = 0;
const int analogPin = A0;
const int servoPin = 8;

void setup() {
  servo.attach(servoPin);
  servo.write(angle);
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{ 
  int tempVal = 0;
  tempVal = analogRead(analogPin);
  tempVal = map(tempVal, 700, 900, 0, 180);
  angle = tempVal;
  servo.write(angle);
}
