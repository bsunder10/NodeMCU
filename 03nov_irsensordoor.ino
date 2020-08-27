#define irout 4
#define lig 6
int cou = 0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(irout,INPUT);
pinMode(lig,OUTPUT);
digitalWrite(lig,LOW);
}


void loop() {
  // put your main code here, to run repeatedly:
val = digitalRead(irout);
if(val == 0)
{
   cou += 1;
   delay(1000);
}
if(cou%2 == 1)
{
  digitalWrite(lig,HIGH);
}
else
{
  digitalWrite(lig,LOW);
}
}
