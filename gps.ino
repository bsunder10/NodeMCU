#include <TinyGPS++.h>
#include<SoftwareSerial.h>

TinyGPSPlus gps;
SoftwareSerial ss(2, 3);  //Rx, Tx
void setup(){
  Serial.begin(9600);
  ss.begin(9600);
 
}

void loop(){
  Serial.print("..");
  while (ss.available() > 0){
    gps.encode(Serial.read());
    if (gps.location.isUpdated()){
      Serial.print(" My location is http://maps.google.com/maps?q=");
     Serial.print(gps.location.lat(), 6);
    Serial.print(",");
    Serial.println(gps.location.lng(), 6);
    delay(1000);
    }
    else{
      Serial.println("Could not find the gps location");
    }
  }}
