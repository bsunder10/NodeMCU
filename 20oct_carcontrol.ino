#define us 4
#define ds 5
#define ls 6
#define rs 7
#define lw 9
#define rw 10

void setup() {
  // put your setup code here, to run once:
pinMode(us,INPUT);
pinMode(ds,INPUT);
pinMode(ls,INPUT);
pinMode(rs,INPUT);
pinMode(lw,OUTPUT);
pinMode(rw,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if(us==HIGH)
{
  digitalWrite(rw,HIGH);
  digitalWrite(lw,HIGH);
}
if(ds==HIGH)
{
  digitalWrite(rw,LOW);
  digitalWrite(lw,LOW);
}
if(ls==HIGH)
{
  digitalWrite(rw,HIGH);
  digitalWrite(lw,LOW);
}
if(rs==HIGH)
{
  digitalWrite(rw,LOW);
  digitalWrite(lw,HIGH);
}
}
