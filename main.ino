#include "properties.h"

//global variables
int waterLevel;
int moisture;
boolean lightOn = false;
long lastPumpTime = millis();
const long pumpCooldownPeriod = 5 * 60 * 1000; // 5 minutes in milliseconds

//include files
#include "sensor.h"
#include "webserver.h"

void setup() {
  //setup pins and serial output
  Serial.begin(115200);
  Wire.begin();

  pinMode(moistureSensor, INPUT);

  //pinMode(waterLevelSensorPower, OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(pump, OUTPUT);

  //deactivate all sensors at the beginning
  digitalWrite(light, LOW);
  digitalWrite(pump, LOW);

  setupWebserver();
}

void loop() {
  checkPump();
  Serial.println("--------------------------");
  Serial.print("Water level: ");
  Serial.print(waterLevel);
  Serial.println("%");
  
  Serial.print("Moisture: ");
  Serial.print(moisture);
  Serial.println("%");
  Serial.println("--------------------------");

  delay(2000);
}