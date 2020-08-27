#define res A0
#define led 11

void setup() {
  // put your setup code here, to run once:
pinMode(res,INPUT);
pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(led,val);
}
