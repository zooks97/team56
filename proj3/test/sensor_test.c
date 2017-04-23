#include "../lib/sensor.h"
//#include "../lib/data.h"

#define HALLPORT S1

task main(){
	while(true){
	    motor[motorC] = 10;
	    displayString(3, "S1 Value: %d", SensorValue[S1]);
	    displayString(5, "S2 Value: %d", SensorValue[S2]);
	    displayString(7, "Hall Test: %d", hallSensor());
	    wait1Msec(100);
	}
}
