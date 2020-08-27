#include<ESP8266WiFi.h>
const char *ssid = "SUNDER";
const char *password = "qwert12345";
int led = D0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.begin(ssid,password);
delay(2000);
while(WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.println(".");

}
Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led,LOW);
delay(1000);
digitalWrite(led,HIGH);
delay(2000);
}
