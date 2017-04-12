/**** TEAM 56 ****/
// PoC Task 4 //
// PoC Task 5 //
// Integration //

#include "../lib/motion.h"
#include "../lib/data.h"
#include "../lib/sensor.h"
#include "../lib/antenna.h"

task main(){
		//move forward 0.45m
    forward(450, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;
    //stop

    //turn 90deg clockwise
    zeroLeft(90, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;

    //move forward 0.20m
    forward(200, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;

    //begin a moving turn radius 0.15m 90deg
    movingLeft(150, 145, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;

    //move forward 0.10m
    forward(100, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;

    //begin polling hall sensor
		while (hallSensor() < 95) {
			  motor[motorA] = 20 //- (hallSensor() / 2);
			  motor[motorB] = 20 //- (hallSensor() / 2);
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

		drop();
		backward(5, 10);

    return;
}
