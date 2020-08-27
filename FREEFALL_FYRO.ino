
#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
float ax=0, ay=0, az=0, gx=0, gy=0, gz=0;

//int data[STORE_SIZE][5]; 
//byte currentIndex=0; 
boolean fall = false; 
boolean trigger1=false;
boolean trigger2=false;
boolean trigger3=false;

byte trigger1count=0;
byte trigger2count=0;
byte trigger3count=0;
int angleChange=0;


void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
  Serial.begin(9600);

  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
}
void loop(){
  
  mpu_read();
  ax = (AcX-2050)/16384.00;
  ay = (AcY-77)/16384.00;
  az = (AcZ-1947)/16384.00;
  
  //270, 351, 136 for gyroscope
  gx = (GyX+270)/131.07;
  gy = (GyY-351)/131.07;
  gz = (GyZ+136)/131.07;
  
  // calculating Amplitute vactor for 3 axis
  float Raw_AM = pow(pow(ax,2)+pow(ay,2)+pow(az,2),0.5);
  int AM = Raw_AM * 10;  // as values are within 0 to 1, I multiplied 
                         // it by for using if else conditions 
  
  Serial.println(AM);
  //Serial.println(PM);
  //delay(500);

  if (trigger3==true){
     trigger3count++;
     //Serial.println(trigger3count);
     if (trigger3count>=10){ 
        angleChange = pow(pow(gx,2)+pow(gy,2)+pow(gz,2),0.5);
        //delay(10);
        Serial.println(angleChange); 
        if ((angleChange>=0) /*&& (angleChange<=10)*/){ 
            fall=true; trigger3=false; trigger3count=0;
          Serial.println(angleChange);
              }
       else{ 
           trigger3=false; trigger3count=0;
           Serial.println("TRIGGER 3 DEACTIVATED");
        }
      }
   }
  if (fall==true){ //in event of a fall detection
    Serial.println("FALL DETECTED");
    digitalWrite(11, LOW);
    delay(20);
    digitalWrite(11, HIGH);
    fall=false;
   // exit(1);
    }
  if (trigger2count>=6){ //allow 0.5s for orientation change
    trigger2=false; trigger2count=0;
    Serial.println("TRIGGER 2 DECACTIVATED");
    }
  if (trigger1count>=6){ 
    trigger1=false; trigger1count=0;
    Serial.println("TRIGGER 1 DECACTIVATED");
    }
  if (trigger2==true){
    trigger2count++;
    //angleChange=acos(((double)x*(double)bx+(double)y*(double)by+(double)z*(double)bz)/(double)AM/(double)BM);
    angleChange = pow(pow(gx,2)+pow(gy,2)+pow(gz,2),0.5); Serial.println(angleChange);
    if (angleChange>=30 && angleChange<=400){ //if orientation changes by between 80-100 degrees
      trigger3=true; trigger2=false; trigger2count=0;
      Serial.println(angleChange);
      Serial.println("TRIGGER 3 ACTIVATED");
        }
    }
  if (trigger1==true){
    trigger1count++;
    if (AM>=12){ //if AM breaks upper threshold (3g)
      trigger2=true;
      Serial.println("TRIGGER 2 ACTIVATED");
      trigger1=false; trigger1count=0;
      }
    }
  if (AM<=2 && trigger2==false){ //if AM breaks lower threshold (0.4g)
    trigger1=true;
    Serial.println("TRIGGER 1 ACTIVATED");
    }
//It appears that delay is needed in order not to clog the port
  delay(100);
}

void mpu_read(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true); 
  AcX=Wire.read()<<8|Wire.read();   
  AcY=Wire.read()<<8|Wire.read(); 
  AcZ=Wire.read()<<8|Wire.read();  
  Tmp=Wire.read()<<8|Wire.read(); 
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read(); 
