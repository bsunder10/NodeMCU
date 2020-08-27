#include<ESP8266WiFi.h>
#include<Adafruit_MQTT.h>
#include<Adafruit_MQTT_Client.h>

float motor, val, duration ;

************************************************************
const char *sssid = "dsfas" ;                 //wifi username
const char *pass = "ksdflkjksd";                       //wifi password 
**********************************************************
#define ledr 02
#define ledy 03
#define ledg 04
#define trig 05
#define echo 06
***********************************************************
#define AIO_SERVER       "io.adafruit.com"
#define AIO_SERVERPORT    1883

#define AIO_USERNAME      "  "       //Adafruit username
#define AIO_KEY           "   "      //Adafruit Key
*************************************************************

WiFiClient client;

//setting up Client
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

//entering the data to feeds  Enter the feed name at last 
Adafruit_MQTT_Publish level = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/ ");
 


void MQTT_connect();

void setup()
{
  Serial.begin(9600);
  WiFi.begin(sssid,pass);
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");

    Serial.println("WiFi connected");
    Serial.println("IP Address is  ");
    Serial.print(WiFi.localIP());
  }
  //Setting up the pins
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  //Setting the pin value as low
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
}

void loop()
{
  //getting the values of ultrasonic sensor
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  duration = pulseIn(tig,LOW);
  val = 0.01715 * duration;


//glowing the leds and turning ON and OFF motor
  if(val < 25)
  {
    digitalWrite(ledr, LOW);
    digitalWrite(ledg, HIGH);
    digitalWrite(ledy, HIGH);
    digitalWrite(motor, LOW);
  }
  else if(val < 60 && val > 25)
  {
    digitalWrite(ledy, LOW);
    digitalWrite(ledg, HIGH);
    digitalWrite(ledr, HIGH);
  }
  else
  {
    digitalWrite(ledg, LOW);
    digitalWrite(ledy, HIGH);
    digitalWrite(ledr, HIGH);
    digitalWrite(motor, HIGH);
  }
  delay(1000);
  
  //publishing the values to the feed
    MOTT_connect();
  
  if (!level.publish(val))
  {
    Serial.println(F("OK!"));
  }
  else
  {
    Serial.println()
  }
}


void MQTT_connect() 
{
  int8_t ret;
  // Stop if already connected.
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
