#define sen A0
#define led 5

void setup() {
  // put your setup code here, to run once:
pinMode(sen,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val;
val=analogRead(sen);
Serial.println(val);
analogWrite(led,val);
}
