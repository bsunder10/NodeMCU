#include <ThingerESP8266.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ThingerWifi.h>
#include "DHT.h"
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  USERNAME "bsunder"
#define DEVICE_ID  "ESP8266"
#define DEVICE_CREDENTIAL "IMbT2voyBx4!"
#define SSID "Niltech"
#define SSID_PASSWORD "Niltech@12345"
//################################################################################################################
#define RELAY_1 LED_BUILTIN
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(RELAY_1, OUTPUT);
  thing.add_wifi(SSID, SSID_PASSWORD);
  Serial.begin(115200);
  dht.begin();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  thing["ESP8266"] >> [](pson& out){
    // Add the values and the corresponding code
    out["hum"] = dht.readHumidity();
    out["temp"] = dht.readTemperature();
    int a = dht.readHumidity();
    int b = dht.readTemperature();
    Serial.println(a);
    Serial.print(b);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    thing["led"] << [](pson& in){
      if (in.is_empty()){
        in = (bool)digitalRead(RELAY_1);
      }
      
      else{
    digitalWrite(RELAY_1, in ? HIGH:LOW);
   
    //in ["relay"] = digitalPin(D5);
     //thing["relay_1"] << [](pson& in){
      //digitalWrite(RELAY_1, in ? HIGH );
      //Serial.println("hello");
}  
};
};
}
void loop() {
  thing.handle();
}
 
