
#define sensorPower 7
#define sensorPin A1
#define motorPin 3
 // Define max value we consider soil 'wet'
#define soilWet 790// Define maxx value for dry
#define soilDry 600  // Define min value we consider soil 'dry'

void setup() {
	pinMode(sensorPower, OUTPUT);
	pinMode(motorPin, OUTPUT);
	// Initially keep the sensor OFF
	digitalWrite(sensorPower, LOW);
	
	Serial.begin(9600);
}

void loop() {
	//get the reading from the function below and print it
	Serial.print("Analog output: ");
	Serial.println(readSensor());
    int moisture = readSensor();
  
	Particle.publish("Moisture", String(moisture), PRIVATE);
	delay(1000);
	
	
	if (moisture < soilDry) {
		digitalWrite(motorPin, HIGH);
		delay(6000); 
	
		
	} else {
	    digitalWrite(motorPin, LOW);
		delay(6000); 
		
	}
}

//  This function returns the analog soil moisture measurement
int readSensor() {
	digitalWrite(sensorPower, HIGH);	// Turn the sensor ON
	delay(10);							// Allow power to settle
	int val = analogRead(sensorPin);	// Read the analog value form sensor
	digitalWrite(sensorPower, LOW);		// Turn the sensor OFF
	return val;							// Return analog moisture value
}


