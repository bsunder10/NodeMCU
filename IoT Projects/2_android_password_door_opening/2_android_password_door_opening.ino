#include<Servo.h>
#include<SoftwareSerial.h>

//conneting the bluetooth
SoftwareSerial ss(2, 3);          //Rx, Tx

Servo myservo;
char varr = 0;
String inputstring = "";

void setup() {
  myservo.attach(9);        //connect servo motor to 9th pin
  // Servo with an ange 0 degrees
  myservo.write(0);         
}

void loop() {
  // getting the value from bluetooth
  while(ss.available() > 0)
  {
    varr = (char)ss.read();
    inputstring += varr;
    
    // opening the door if password is correct
    if(inputstring == "12345")
    {
      myservo.write(90);          //rotates servo motor to 90 degrees
    }
  }
}
