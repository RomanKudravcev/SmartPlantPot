//wrong sensor
//will be replaced

int checkWaterLevel(){
    int val;
  	digitalWrite(waterLevelSensorPower, HIGH);	// Turn the sensor ON
	delay(10);							        // wait 10 milliseconds
	val = analogRead(waterLevelSensor);         // Read the analog value form sensor
	digitalWrite(waterLevelSensorPower, LOW);	// Turn the sensor OFF
	return val;							        // send current reading
}
