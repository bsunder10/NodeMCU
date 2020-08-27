#define xpos A0
#define ypos A1
#define zpos A2

int a, b, c;

void setup() {
  Serial.begin(9600);
  
  pinMode(xpos, INPUT);
  pinMode(ypos, INPUT);
  pinMode(zpos, INPUT);
}

void loop() {
  a = analogRead(xpos);
  b = analogRead(ypos);
  c = analogRead(zpos);

  Serial.println(a);
  Serial.println(b);
  Serial.println(c);

  Serial.println("**************");

  delay(1000);
}



//370   280
