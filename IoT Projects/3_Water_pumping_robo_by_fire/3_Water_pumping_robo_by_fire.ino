#include<SoftwareSerial.h>

//connecting bluetooth to arduino
SoftwareSerial ss(2, 3);          //Rx, Tx

char varr = 0;
String inputstring = "";

#define ip1 4
#define ip2 5
#define ip3 6
#define ip4 7
#define pump 8

void setup() {
  //defining the pins
  pinMode(ip1, OUTPUT);
  pinMode(ip2, OUTPUT);
  pinMode(ip3, OUTPUT);
  pinMode(ip4, OUTPUT);
  pinMode(pump, OUTPUT);
  //setting all the values to zero initially
  digitalWrite(ip1, LOW);
  digitalWrite(ip2, LOW);
  digitalWrite(ip3, LOW);
  digitalWrite(ip4, LOW);
  digitalWrite(pump, LOW);  
}


//function to move straight
int forward()
{
  digitalWrite(ip1, HIGH);
  digitalWrite(ip1, LOW);
  digitalWrite(ip1, HIGH);
  digitalWrite(ip1, LOW);
}
//function to move backward
int reverse()
{
  digitalWrite(ip1, LOW);
  digitalWrite(ip1, HIGH);
  digitalWrite(ip1, LOW);
  digitalWrite(ip1, HIGH);
}
//function to turn left
int left()
{
  digitalWrite(ip1, HIGH);
  digitalWrite(ip1, LOW);
  digitalWrite(ip1, LOW);
  digitalWrite(ip1, HIGH);
}
//function to trun right
int right()
{
  digitalWrite(ip1, LOW);
  digitalWrite(ip1, HIGH);
  digitalWrite(ip1, HIGH);
  digitalWrite(ip1, LOW);
}
//function to stop
int stopp()
{
  digitalWrite(ip1, LOW);
  digitalWrite(ip1, LOW);
  digitalWrite(ip1, LOW);
  digitalWrite(ip1, LOW);
}


void loop() {
  // get the values from the bluetooth
  while(ss.available() > 0)
  {
  varr = (char)ss.read();
  inputstring += varr;
  
  //moving the robot 
  if(varr == 'f')
  {
    forward();
  }
  else if(varr == 'b')
  {
    reverse();
  }
  
  else if(varr == 'l')
  {
    left();
  }

  else if(varr == 'r')
  {
    right();
  }

  else if(varr == 's')
  {
    stopp();
  }
}

//Finding the temperature


}
