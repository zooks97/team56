/**** TEAM 56 ****/
// ANTENNA DELIVERY //

void drop();

void drop(){
    //zero motor
    nMotorEncoder[motorA] = 0;
    motor[motorA] = 0;
    //set target and run
    nMotorEncoderTarget[motorA] = -20;
    motor[motorA] = -50;
    while(nMotorRunState[motorA] != runStateIdle){}
    //stop and wait
    motor[motorA] = 0;
    wait1Msec(100);

    //set target and run
    nMotorEncoderTarget[motorA] = 40;
    motor[motorA] = 10;
    while(nMotorRunState[motorA] != runStateIdle){}
    //stop and wait
    motor[motorA] = 0;
    wait1Msec(500);

    return;
}
