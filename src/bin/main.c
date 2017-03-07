#include "../libs/motion.h"
#include "../libs/data_cleaning.h"

//28.4 = 30

////PID straight test v1
task main(){
    float pow = 80;
    motor[motorA] = 0;
    motor[motorB] = 0;
    zeroTurn(28.4, pow/2);
    motor[motorA] = 0;
    motor[motorB] = 0;
    wait1Msec(100);
    straight(1000, pow);
    displayTextLine(1, "%d", nImmediateBatteryLevel);
    wait1Msec(100);
    bFloatDuringInactiveMotorPWM = true;
}
