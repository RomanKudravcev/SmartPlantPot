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