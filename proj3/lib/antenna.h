/**** TEAM 56 ****/
// ANTENNA DELIVERY //

void drop();

void drop(){
    nMotorEncoder[motorA] = 0;
    motor[motorA] = 0;
    nMotorEncoderTarget[motorA] = -20;
    motor[motorA] = -50;
    while(nMotorRunState[motorA] != runStateIdle){}
    motor[motorA] = 0;
    wait1Msec(100);

    nMotorEncoderTarget[motorA] = 40;
    motor[motorA] = 10;
    while(nMotorRunState[motorA] != runStateIdle){}
    motor[motorA] = 0;
    wait1Msec(500);

    return;
}
