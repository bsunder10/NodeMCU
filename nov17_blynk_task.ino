

#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

char auth[] = "IzlXqqpDXkGc6dnoR7DQ0YRqFwfKNqCd";

const char *ssid = "HOME";
const char *password = "qwert12345";

int led = D0;
int ldr = D1;
int pir = D2;
int soil = A0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  Blynk.begin(auth,ssid,password);

  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(soil,INPUT);
  pinMode(pir,INPUT);
  
}

void loop() {
  

if(ldr == 1 || soil > 500 || pir == 1)
{
  digitalWrite(led,HIGH);
  
}

Blynk.run();
}
