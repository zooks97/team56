#include "../lib/sensor.h"
#include "../lib/data.h"

#define HALLPORT S1

task main(){
	while(true){
	    displayString(3, "Value: %d", sensorValue[HALLPORT]);
	    wait1Msec(100);
	}
}
