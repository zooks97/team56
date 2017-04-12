/**** TEAM 56 ****/
// PoC Task 4 //

#include "../lib/motion.h"
#include "../lib/data.h"
#include "../lib/sensor.h"

task main(){
    //begin polling hall sensor
		while (hallEffect() < 95) {
			  motor[motorA] = 50 - (hallEffect() / 2);
			  motor[motorB] = 50 - (hallEffect() / 2);
		}

		motor[motorA] = 0;
		motor[motorB] = 0;
		wait1Msec(500);

		forward(5, 10);

		playImmediateTone(440, 2);
		wait1Msec(200);
		playImmediateTone(440, 2);
		wait1Msec(200);
		playImmediateTone(440, 2);
		wait1Msec(200);

    return;
}
