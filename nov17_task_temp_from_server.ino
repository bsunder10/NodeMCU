#include<ESP8266WiFi.h>
#include<ArduinoJson.h>
#include<ESP8266HTTPClient.h>

const char *ssid = "HOME";
const char *password = "qwert12345";

String location = "Hyderabad,IN";
String API_Key = "11b7ee2e8a78f34df5e2c272ae093e86";

float temp,Humidity,pressure,windspeed,winddegree;

HTTPClient http;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500);

  WiFi.begin(ssid,password);
  delay(2000);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("connected");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.RSSI());
}

void loop() {
  // put your main code here, to run repeatedly:

  http.begin("http://api.openweathermap.org/data/2.5/weather?q=" + location + "&APPID=" + API_Key);
  
  int httpCode = http.GET();

  if (httpCode > 0)
  {
    String payload = http.getString();

DynamicJsonDocument jsonBuffer(512);
JsonObject root = jsonBuffer.as<JsonObject>();

    float temp = (float)(root["main"]["temp"]) - 273.15;
    float Humidity = root["main"]["humidity"];
    float pressure = (float)(root["main"]["pressure"]) / 1000;
    float windspeed = root["wind"]["speed"];
    int winddegree = root["wind"]["deg"];

   
    }

    Serial.println(temp);
    Serial.println(Humidity);
    Serial.println(pressure);
    Serial.println(windspeed);
    Serial.println(winddegree);
    Serial.println("**********************************");
    delay(5000);
}
