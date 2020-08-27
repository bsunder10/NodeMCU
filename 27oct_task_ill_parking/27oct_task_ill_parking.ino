#include<LiquidCrystal.h>

const unsigned long period = 5000;
//#define trig 9
#define echo 8
LiquidCrystal lcd(7,6,5,4,3,2);
unsigned long pre;
unsigned long past;

void setup() {
  // put your setup code here, to run once:
//pinMode(trig,OUTPUT);
Serial.begin(9600);
pinMode(echo,INPUT);
lcd.begin(16,2);



delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:IN  int period = 5000;
long duration,cm;
past = millis();
Serial.println(past);
//delay(1000);
/*
digitalWrite(trig, LOW);
delayMicroseconds(5);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
pinMode(echo,INPUT);
duration = pulseIn(echo,HIGH);
cm = 0.0343 * duration/2;
*/
int val = digitalRead(echo);

//Serial.println(val);
while(val == LOW)
{
  here:pre = millis();
  if(pre - past >= period)
  {
    Serial.println("ILLIGAL PARKING");
    goto here;
  }
  else
  {
    Serial.println("CAN PARK");
  }
}
 pre = past; 

}
