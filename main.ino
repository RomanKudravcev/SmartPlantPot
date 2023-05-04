#include "properties.h"

//local variables
int waterLevel;
int moisture;
boolean lightOn = false;

//include files
#include "sensor.h"
#include "webserver.h"

void setup() {
  //setup pins and serial output
  Serial.begin(115200);

  pinMode(waterLevelSensor, INPUT);
  pinMode(moistureSensor, INPUT);

  //pinMode(waterLevelSensorPower, OUTPUT);
  pinMode(light, OUTPUT);

  //deactivate all sensors at the beginning
  digitalWrite(light, LOW);

  setupWebserver();
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