
int v;
void setup() {
  // put your setup code here, to run once:
pinMode(10,INPUT);
pinMode(3,OUTPUT);
digitalWrite(3,LOW);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
v = digitalRead(10);
Serial.print(v);
if(v == HIGH)
{
  digitalWrite(3,LOW);
}
else
{
  digitalWrite(3,HIGH);
}
delay(1000);
}
