#define sen1 A0
#define sen2 A1
#define sen3 5
#define red 13
#define blue 12
#define green 11


void setup() {
  // put your setup code here, to run once:
  pinMode(sen1,INPUT);
  pinMode(sen2,INPUT);
  pinMode(sen3,INPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  
}

void loop() {
 // put your main code here, to run repeatedly:
int senr1,senr2,senr3;


senr1=analogRead(sen1);
senr2=analogRead(sen2);
senr3=digitalRead(sen3);

if (senr1>50)
{
  digitalWrite(red,HIGH);
}
else if(senr2<85)
{
  digitalWrite(blue,HIGH); 
}
else if(senr3==HIGH)
{
  digitalWrite(green,LOW);
  
}
else
{
  digitalWrite(red,LOW);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
  
}

}
