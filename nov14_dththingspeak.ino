#include<ESP8266WiFi.h>
#include<DHT.h>
//#include<Adafruit_Sensor.h>

#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

float hum = 0.0;
float temp = 0.0;

String apiKey = "5HBPYTWLYRK3LASS";

const char *ssid = "Niltech";
const char *password = "Niltech@12345";
const char *server = "api.thingspeak.com";

WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  WiFi.begin(ssid,password);
  dht.begin();
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(50);
  }
Serial.println("Connected");
Serial.println(WiFi.localIP());

//pinMode(DHTPIN,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.println(hum);
  Serial.println(temp);

    if(client.connect(server,80))
    {
      String poststr = apiKey;
      poststr += "&field1=";
      poststr += String(hum);
      poststr += "&field2=";
      poststr += String(temp);
      poststr += "\r\n\r\n";
    
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: "); 
    client.print(poststr.length());
    client.print("\n\n");
    client.print(poststr);
    Serial.println("ii");
    }
 client.stop();

 delay(1000);
}
