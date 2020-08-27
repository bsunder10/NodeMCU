

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "DHT.h"

#define DHTPIN 04
#define sen1 16
#define sen2 03
#define sen3 A0    // analog sensor

#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

float hum, temp, a, b , a1, d1, d2;

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "Niltech"     //username
#define WLAN_PASS       "Niltech@12345"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL


#define AIO_USERNAME    "sunderb"
#define AIO_KEY         "f52326c53c4f4c26aed698a559f2d627"


WiFiClient client;


// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);





Adafruit_MQTT_Publish temppFeed = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temp");
Adafruit_MQTT_Publish hummFeed = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/hum");
Adafruit_MQTT_Publish digsen1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/ir");
//Adafruit_MQTT_Publish digsen2 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/  ");
//Adafruit_MQTT_Publish anasen1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/  ");



void MQTT_connect();
void setup() {
   Serial.begin(9600);
    Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.print(WiFi.localIP());
  dht.begin();
 
}

void loop() {
 
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  Serial.print("temp");
  Serial.println(temp);
  Serial.print("hum");
  Serial.println(hum);

  d1 = digitalRead(sen1);
  Serial.println(d1);
  d2 = digitalRead(sen2);
  a1 = analogRead(sen3);
  
 delay(1000);
 MQTT_connect();

  if (! temppFeed.publish(temp))
  {
    Serial.println(F("Failed"));
  } 
  
  else 
  {
    Serial.println(F("OK!"));
    delay(1000);
  }

 
   if (! hummFeed.publish(hum))
  {
    Serial.println(F("Failed"));
  } 
  
  else 
  {
    Serial.println(F("OK!"));
    delay(1000);
  }


 if (! digsen1.publish(d1))
  {
    Serial.println(F("Failed"));
  } 
  
  else 
  {
    Serial.println(F("OK!"));
    delay(1000);
  }


delay(1000);
  

}



void MQTT_connect() 
{
  int8_t ret;
  // Stop if already connected.
  if (mqtt.connected()) 
  {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) 
    { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) 
       {
         // basically die and wait for WDT to reset me
         while (1);
       }
    }
  Serial.println("MQTT Connected!");
}
