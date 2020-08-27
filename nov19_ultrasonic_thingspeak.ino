#include <ESP8266WiFi.h>
String apiKey = "9O1HFF1ZGXXGY7XM";     //  Enter your Write API key from ThingSpeak

const char *ssid =  "Niltech";     // replace with your wifi ssid and wpa2 key
const char *pass =  "Niltech@12345";
const char* server = "api.thingspeak.com";
int sen1 = D0;
int sen2 = D1;
int sen3 = D2;
int trig = D4;

WiFiClient client;
void setup() {
  Serial.begin(115200);
       delay(10);
       
 pinMode(sen1,INPUT);
 pinMode(sen2,INPUT);
 pinMode(sen3,INPUT);
 pinMode(trig,OUTPUT);
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
 



void loop() {

float val1,val2,val3;
float duration1,duration2,duration3;


digitalWrite(trig,HIGH);
delayMicroseconds(2);
digitalWrite(trig,LOW);
delayMicroseconds(10);
digitalWrite(trig,HIGH);
duration1 = pulseIn(sen1,LOW);
val1 = 0.01715 * duration1;
duration2 = pulseIn(sen2,LOW);
val2 = 0.01715 * duration2;
duration3 = pulseIn(sen3,LOW);
val3 = 0.01715 * duration3;

   if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += String(val1);
                             postStr +="&field2=";
                             postStr += String(val2);
                             postStr +="&field3=";
                             postStr += String(val3);
                             postStr += "\r\n\r\n\r\n";
                             
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                        }
          client.stop();
 
           
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
}
