#define BLYNK_PRINT DebugSerial
#define DHTPIN 12
#define DHTTYPE DHT11

// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
#include "DHT.h"
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>
int pirPin = 9;
int relay1 = 7;
int relay2 = 6;
int relay3 = 5;
DHT dht(DHTPIN , DHTTYPE);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2HpsYqfFyWlZvNXKpr05n8PNksefahJI";


void setup()
{
  pinMode(pirPin, INPUT);
  pinMode(relay1 , OUTPUT);
  pinMode(relay2 , OUTPUT);
  pinMode(relay3 , OUTPUT);
  // Debug console
  DebugSerial.begin(9600);

  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  dht.begin();
}

void loop()
{
  Blynk.run();
  //DHT humidity
  Blynk.virtualWrite(V1, dht.readHumidity());
  //dht Temperature
  Blynk.virtualWrite(V2, dht.readTemperature());
   motion_status();
}

void motion_status(){
  if(digitalRead(pirPin)){
    Blynk.virtualWrite(V0, "Motion is detected");
  }else{
    Blynk.virtualWrite(V0, "......");
  }
}

BLYNK_WRITE(V3){
  if(param.asInt()){
    digitalWrite(relay1,HIGH);
    Blynk.virtualWrite(V4,"ON");
  }else{
    digitalWrite(relay1,LOW);
    Blynk.virtualWrite(V4,".....");
  }
}


BLYNK_WRITE(V5){
  if(param.asInt()){
    digitalWrite(relay2,HIGH);
    Blynk.virtualWrite(V4,"ON");
  }else{
    digitalWrite(relay2,LOW);
    Blynk.virtualWrite(V4,".....");
  }
}


BLYNK_WRITE(V6){
  if(param.asInt()){
    digitalWrite(relay3,HIGH);
    Blynk.virtualWrite(V4,"ON");
  }else{
    digitalWrite(relay3,LOW);
    Blynk.virtualWrite(V4,".....");
  }
}
