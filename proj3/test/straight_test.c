/**** TEAM 56 ****/
// straight test//

#include "../lib/motion.h"

task main(){
    nMotorPIDSpeedCtrl[motorB] = mtrSpeedReg;
    nMotorPIDSpeedCtrl[motorC] = mtrSpeedReg;
    wait1Msec(500);
    forward(300, 30);
}
