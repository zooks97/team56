#include "../libs/motion.h"
#include "../libs/data_cleaning.h"

////PID straight test v1
task main(){
    float pow = 50;
    //straight(609.6, pow);
    bFloatDuringInactiveMotorPWM = true;
    zeroTurn(30, pow/2);
    bFloatDuringInactiveMotorPWM = false;
    motor[motorA] = 0;
    motor[motorB] = 0;
    wait1Msec(500);
    bFloatDuringInactiveMotorPWM = true;
}
