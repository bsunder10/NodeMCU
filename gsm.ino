void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

  //To send SMS
  Serial.println("AT+CMGF=1");   
  delay(1000);  
  Serial.println("AT+CMGS=\"+91\"\r"); 
  delay(1000);
  Serial.print(" My location is http://maps.google.com/maps?q=");
  delay(100);
  Serial.println((char)26);
  delay(5000);
  //To call
  Serial.println("ATD++91");
}

void loop() {
  // put your main code here, to run repeatedly:
    }
