#include <SPI.h>
#include <ESP8266WiFi.h>

byte ledPin = 2;
char ssid[] = "**********";      
char pass[] = "*********";       

unsigned long askTimer = 0;

IPAddress server(192,168,0,80);  
WiFiClient client;

void setup() {
  Serial.begin(115200);         
  WiFi.begin(ssid, pass);       
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
/*  Serial.println("Connected to wifi");
  Serial.print("Status: "); Serial.println(WiFi.status());    // Network parameters
  Serial.print("IP: ");     Serial.println(WiFi.localIP());
  Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("Signal: "); Serial.println(WiFi.RSSI());*/
  pinMode(ledPin, OUTPUT);
}

void loop () {
  client.connect(server, 80);   
  digitalWrite(ledPin, LOW);    
  Serial.println(".");
  client.println("Hello server! Are you sleeping?\r");
  String answer = client.readStringUntil('\r');
  Serial.println("from server: " + answer);
  client.flush();
  digitalWrite(ledPin, HIGH);
  delay(2000);                  
}
