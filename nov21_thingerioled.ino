#include <ThingerESP8266.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ThingerWifi.h>
#include<DHT.h>

#define led D0
#define DHTPIN D2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

float hum,temp,a,b;

#define USERNAME "bsunder"
#define DEVICE_ID "ESP8266"
#define DEVICE_CREDENTIAL "IMbT2voyBx4!"
#define WLAN_SSID "Niltech"
#define WLAN_pass "Niltech@12345"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
dht.begin();


Serial.begin(115200);
WiFi.begin(WLAN_SSID,WLAN_pass);
//delay(2000);
while(WiFi.status() != WL_CONNECTED)
{
  Serial.print(".");
  delay(50);
}
Serial.println("connected");

  a = dht.readHumidity();
  b = dht.readTemperature();
  Serial.println(a);
  Serial.print(b);


thing["ESSSP8266"] >> [](pson& out){
  
  out["hum"] = dht.readHumidity();
  out["temp"] = dht.readTemperature();
  
thing["ESP8266"] << [](pson& in){
  if(in.is_empty())
  {
    in = (bool)digitalRead(led);
  }
  else{
    digitalWrite(led, in ? HIGH:LOW);
  }

 /* thing["ledd"] >> [](pson& out){
    out["lled"] = digitalRead(led); 
  };*/
};
};
}


void loop() {
  // put your main code here, to run repeatedly:
  thing.handle();
}
