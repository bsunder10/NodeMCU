#include<TimerOne.h>
void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
//Timer1.initialize(1000);
Timer1.pwm(10,255);

}

void loop() {
  // put your main code here, to run repeatedly:

}
