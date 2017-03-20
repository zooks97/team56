/**** TEAM 56 ****/
// PoC Task 5 //

#include "../lib/motion.h"
#include "../lib/bin.h"

//FIXME//
//THIS NEEDS TO BE UPDATED AFTER//
//ZERO TURN HAS BEEN FIXED FOR//
//NEGATIVE ANGLES//
task main(){
    //move forward 0.45m
    straight(450, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;
    //stop

    //turn 90deg clockwise
    zeroTurn(90, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;

    //move forward 0.20m
    straight(200, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;

    //begin a moving turn radius 0.15m 90deg
    movingTurn(150, 90, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;

    //move forward 0.30m
    straight(300, 30);

    wait1Msec(500);
    motor[motorA] = 0;
    motor[motorB] = 0;

    //stop

    //drop bin

    return;
}
