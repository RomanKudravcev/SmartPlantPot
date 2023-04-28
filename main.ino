//define pins
#define waterLevelSensor 14
#define waterLevelSensorPower 27
#define moistureSensor 26

//local variables
int waterLevel;
int moisture;

//include files
#include "waterlevel.h"

void setup() {
  //setup pins and serial output
  Serial.begin(115200);

  pinMode(waterLevelSensor, INPUT);
  pinMode(moistureSensor, INPUT);

  pinMode(waterLevelSensorPower, OUTPUT);

  //deactivate all sensors at the beginning
  digitalWrite(waterLevelSensorPower, LOW);

}

void loop() {
  waterLevel = checkWaterLevel();
  moisture = checkMoisture();

  Serial.print("Water level: ");
  Serial.println(waterLevel);

  Serial.print("Moisture: ");
  Serial.println(moisture);

  delay(2000);
}
