/**** TEAM 56 ****/
// SENSOR FUNCTIONS //
#define HALLPORT1 S1
#define HALLPORT2 S2

bool hallSensor();

bool hallSensor(){
    short sens1 = SensorValue[HALLPORT1];
    short sens2 = SensorValue[HALLPORT2];
    displayString(3, "S1 Value: %d", sensorValue[S1]);
	displayString(5, "S2 Value: %d", sensorValue[S2]);

    if (sens1 > 480 || sens1 < 460 || sens2 > 480 || sens2 < 460) {
        return false;
    } else {
        return true;
    }
}
