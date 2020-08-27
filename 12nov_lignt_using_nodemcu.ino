#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "IzlXqqpDXkGc6dnoR7DQ0YRqFwfKNqCd";

char ssid[] = "Home";
char pass[] = "qwert12345";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}
`

void loop()
{
  Blynk.run();
}
