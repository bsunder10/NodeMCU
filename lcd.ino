#include<LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.setCursor(4,0);
lcd.print("Hi");
lcd.setCursor(2,1);
lcd.print("HII");


}

void loop() {
  // put your main code here, to run repeatedly:

}
