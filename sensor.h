//wrong sensor
//will be replaced
int checkWaterLevel(){
	return analogRead(waterLevelSensor);	// send current reading       
}

//wrong sensor
//will be replaced
int checkMoisture(){
	return analogRead(moistureSensor);		// send current reading
}

void switchLight(){
	if(lightOn == true){
		lightOn = false;
		digitalWrite(light, LOW);
	} else{
		lightOn = true;
		digitalWrite(light, HIGH);
	}
}

void checkPump(){
	long currentTime = millis();
  	waterLevel = checkWaterLevel();
  	moisture = checkMoisture();
  
  	if(waterLevel < 20 || moisture > 3000 || currentTime - lastPumpTime < pumpCooldownPeriod){
		return;
	}

	digitalWrite(pump, HIGH);
    delay(2000); // Run pump for 2 seconds
	digitalWrite(pump, LOW);

	lastPumpTime = currentTime; // Update last pump time

}