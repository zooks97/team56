/**** TEAM 56 ****/
// ANTENNA DELIVERY //

void drop();

void drop(){
    nMotorEncoder[motorC] = 0;
    motor[motorC] = 0;
    nMotorEncoderTarget[motorC] = -20;
    motor[motorC] = -50;
    while(nMotorRunState[motorC] != runStateIdle){}
    motor[motorC] = 0;
    wait1Msec(100);

    nMotorEncoderTarget[motorC] = 40;
    motor[motorC] = 10;
    while(nMotorRunState[motorC] != runStateIdle){}
    motor[motorC] = 0;
    wait1Msec(500);

    return;
}
