#include "motion.h"
task main() {

straight(10000);

}

#include "motion.h"
#include "data_cleaning.h"

////PID straight test v1
task main(){
   float distance = 3000; //mm
//    float angle = 40; //degrees
//    zeroTurn(angle);
//    motor[motorA] = 0;
//    motor[motorB] = 0;
//    displayString(1, "%f", nImmediateBatteryLevel);
//    wait1Msec(1000);
//    //straight(distance);
    speed = batToVel(nImmediateBatteryLevel);
    straight(distance, speed);
//}
