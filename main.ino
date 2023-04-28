//define pins
#define waterLevelSensor 14
#define waterLevelSensorPower 27

//local variables
int waterLevel;

//include files
#include "waterlevel.h"

void setup() {
  //setup pins and serial output
  Serial.begin(115200);
  pinMode(waterLevelSensorPower, OUTPUT);

  //deactivate all sensors at the beginning
  digitalWrite(waterLevelSensorPower, LOW);
}

void loop() {
  waterLevel = checkWaterLevel();
  Serial.print("Water level: ");
  Serial.println(waterLevel);
  delay(2000);
}
