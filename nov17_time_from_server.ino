#include<ESP8266WiFi.h>
#include<NTPClient.h>
#include<WiFiUdp.h>

const char *ssid = "HOME";
const char *password = "qwert12345";

const long utc = 19800;

char day[7][12] = {"Sunday","Monday","Tuesday","Wednesday","Thusday","Friday","Saturday"};

WiFiUDP udp;
NTPClient timeClient(udp,"asia.pool.ntp.org",utc);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  delay(1000);
  
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }
  Serial.println("connected");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.RSSI());

  timeClient.begin();
}

void loop() {
  timeClient.update();
/*
  Serial.print(day[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.print(timeClient.getSeconds());
  Serial.println("   ");*/
  Serial.print(timeClient.getFormattedTime());
  Serial.println("");
  delay(2000);
  // put your main code here, to run repeatedly:

}
