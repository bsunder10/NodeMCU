#define led 6
#define sen A0
int val = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(sen,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val = analogRead(sen);
Serial.println(val);
analogWrite(led,val);
}
