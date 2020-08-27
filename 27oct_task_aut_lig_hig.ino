#define ldr1 2
#define ldr2 3
#define ldr3 4
#define ldr4 5
#define ir1 6
#define ir2 7
#define ir3 8
#define ir4 9
#define ledlef 10
#define ledrig 11

int sun = 800;
int veh = 500;

void setup() {
  // put your setup code here, to run once:
pinMode(ldr1,INPUT);
pinMode(ldr2,INPUT);
pinMode(ldr3,INPUT);
pinMode(ldr4,INPUT);
pinMode(ir1,INPUT);
pinMode(ir2,INPUT);
pinMode(ir3,INPUT);
pinMode(ir4,INPUT);
pinMode(ledlef,OUTPUT);
pinMode(ledrig,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
int val1,val2,val3,val4,val5,val6,val7,val8;
val1=analogRead(ldr1);
val2=analogRead(ldr2);
val3=analogRead(ldr3);
val4=analogRead(ldr4);

val5=digitalRead(ir1);
val6=digitalRead(ir2);
val7=digitalRead(ir3);
val8=digitalRead(ir4);

if(val1 > sun )
{
  digitalWrite(ledlef,LOW);
  digitalWrite(ledrig,LOW);
}
else
{
  if(val5 == LOW or val6 == LOW or val3 < veh)
  {
    digitalWrite(ledlef,HIGH);
    delay(10000);
  }
  else if(val7 == LOW or val8 == LOW or val4 < veh)
  {
    digitalWrite(ledrig,HIGH);
    delay(10000);
  }
}
}
