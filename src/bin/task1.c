/**** TEAM 56 ****/
// PoC Task 1 //

#include "../libs/motion.h"

task main(){
    float pow = 60;

    motor[motorA] = 0;
    motor[motorB] = 0;

    //this does ~30 degrees
    zeroTurn(28.4, pow/2);

    motor[motorA] = 0;
    motor[motorB] = 0;
    wait1Msec(100);

    straight(1200, pow);

    wait1Msec(100);
    bFloatDuringInactiveMotorPWM = true;
}
