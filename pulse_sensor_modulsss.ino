#define USE_ARDUINO_INTERRUPTS true 
#include <PulseSensorPlayground.h> 

// Variables
const int PulseWire = A0; 
const int LED13 = 13;
int Threshold = 510; // Determine which Signal to "count as a beat" and which to ignore.
// Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
// Otherwise leave the default "550" value.

PulseSensorPlayground pulseSensor; // Creates an instance of the PulseSensorPlayground object called "pulseSensor"
void setup() {

Serial.begin(9600); // For Serial Monitor
pulseSensor.analogInput(PulseWire);
pulseSensor.blinkOnPulse(LED13); 
pulseSensor.setThreshold(Threshold);

// Double-check the "pulseSensor" object was created and "began" seeing a signal.
if (pulseSensor.begin()) {
Serial.println("We created a pulseSensor Object !");

}
}

void loop() {


int myBPM = pulseSensor.getBeatsPerMinute(); 
if (pulseSensor.sawStartOfBeat()) { 
//Serial.println("♥ A HeartBeat Happened ! "); 
Serial.print("BPM: "); // Print phrase "BPM: "
Serial.println(myBPM); 
}
//delay(10); 
}
