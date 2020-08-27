#include<ESP8266WiFi.h>
#include<Adafruit_MQTT.h>
#include<Adafruit_MQTT_Client.h>

#define ssid              "Niltech"
#define password          "Niltech@12345"

#define AIO_SERVER        "io.adafruit.com"
#define AIO_SERVERPORT    1883

#define AIO_USERNAME       "sunderb"
#define AIO_KEY            "f52326c53c4f4c26aed698a559f2d627"
const int lightone = 19;

WiFiClient client;

Adafruit_MQTT_Client mqtt (&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe slider = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feed/slide");

 void MQTT_connect();

 void setup()
 {
  Serial.begin(115200);

  WiFi.begin(ssid,password);
  delay(500);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(50);
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  mqtt.subscribe(&slider);
  pinMode(lightone, OUTPUT);
  digitalWrite(lightone, HIGH);
  

  MQTT_connect();
 }

 void loop()
 {
  Adafruit_MQTT_Subscribe *subscription;

      while(subscription = mqtt.readSubscription(1000))
      {
        if(subscription == &slider)
        {
          char *value = (char *)slider.lastread;
          String messege = String(value);
          messege.trim();
          Serial.print(messege);
          if(messege == "10"){
            analogWrite(lightone,0);}
          if(messege == "20"){
            analogWrite(lightone,50);}
          if(messege == "30"){
            analogWrite(lightone,100);}
          if(messege == "40"){
            analogWrite(lightone,150);}
          if(messege == "50"){
            analogWrite(lightone,200);}
          if(messege == "60"){
            analogWrite(lightone,255);}
          
          }
          
        }
      }

void MQTT_connect() 
{
  int8_t ret;
  
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
