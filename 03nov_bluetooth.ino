#define led1 8
#define led2 9
#define led3 10
#define led4 11
char var = 0;
String inputstring = "";


void setup() {
  // put your setup code here, to run once:
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available() > 0)
{
  var = (char)Serial.read();
  inputstring += var;
  Serial.println(var);
 /* switch(var){
  case "(char)fo" :digitalWrite(led1,HIGH);
  case "(char)re":digitalWrite(led2,HIGH);
  case "(char)le":digitalWrite(led3,HIGH);
  case "(char)ri":digitalWrite(led4,HIGH);
  case "(char)st":digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
   */
   if(var == 'a')
   {
    digitalWrite(led1,HIGH);
   Serial.println("fo");
   } 
  else if(var == 'b')
  {
    digitalWrite(led2,HIGH);
  Serial.print("b");
  } 
  else if(var == 'c')
  {
    digitalWrite(led3,HIGH);
    Serial.print("c");
  } 
  else if(var == 'd')
  {
    digitalWrite(led4,HIGH);
  Serial.print("d");
  } 
  else if(var == 'e')
  {
    digitalWrite(led4,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led1,LOW);
  }
  
}
}
