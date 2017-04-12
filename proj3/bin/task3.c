/**** TEAM 56 ****/
// PoC Task 3 //

#include "../lib/motion.h"

task main(){
    float pow = 50;

    motor[motorA] = 0;
    motor[motorB] = 0;
    wait1Msec(100);

    forward(1200, pow);

    wait1Msec(100);
    bFloatDuringInactiveMotorPWM = true;
}
