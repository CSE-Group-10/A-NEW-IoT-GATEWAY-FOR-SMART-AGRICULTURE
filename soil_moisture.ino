#define BLYNK_PRINT DebugSerial


#include <SoftwareSerial.h>

SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>

char auth[] = "T2vy-XvOc0-3NnSc8eevfsQNxSIzJzuk";
int sensor_pin = 12;
int output_value ;

void setup() {

   Serial.begin(9600);

  // Serial.println("Reading From the Sensor ...");
   pinMode(sensor_pin,INPUT);
   // Debug console
  DebugSerial.begin(9600);
 // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Blynk.begin(Serial, auth);

   }

void loop() {
      Blynk.run();
         
 output_value= digitalRead(sensor_pin);
 if(output_value==HIGH){
    Blynk.virtualWrite(V0,"Mostiure  Present");
  }else{
    Blynk.virtualWrite(V0,"Mostiure Not  Present");
  }
}
   
  
