#include<ESP8266WiFi.h>
#include<ArduinoJson.h>
#include<WiFiClient.h>

const char *ssid = "HOME";
const char *password = "qwert12345";
const char server[] = "api.openweathermap.org";

String city = "Hyderabad,IN";
String api = "11b7ee2e8a78f34df5e2c272ae093e86";

WiFiClient client;

void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
WiFi.begin(ssid,password);
delay(2000);
while(WiFi.status() != WL_CONNECTED)
{
  Serial.print(".");
  delay(50);
}
Serial.println("connected");
Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

if(client.connect(server,80))
{
  client.println("GET/data/2.5/forecast?=" + city + "&APPID=" + api);
  client.println("Host: api.openweathermap.org");
  client.println("User-Agent: ArduinoWiFi/1.1");
  client.println("Connection: close");
  client.println();

}

DynamicJsonDocument doc(1024);
JsonObject root = doc.as<JsonObject>();

    float temp = (float)(root["main"]["temp"]) - 273.15;
    float Humidity = root["main"]["humidity"];
    float pressure = (float)(root["main"]["pressure"]) / 1000;
    float windspeed = root["wind"]["speed"];
    int winddegree = root["wind"]["deg"];

    Serial.println(Humidity);
    Serial.println(pressure);
    Serial.println(windspeed);
    Serial.println(winddegree);
    Serial.println("**********************************");
    delay(5000);

}
