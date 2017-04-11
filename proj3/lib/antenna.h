/**** TEAM 56 ****/
// ANTENNA DELIVERY //

void drop();

void drop(){
		nMotorEncoder[motorC] = 0;
		motor[motorC] = 0;
		nMotorEncoderTarget[motorC] = -60;
		motor[motorC] = -50;
		while(nMotorRunState[motorC] != runStateIdle){}
		motor[motorC] = 0;
		wait1Msec(50);

		nMotorEncoderTarget[motorC] = 60;
		motor[motorC] = 50;
		while(nMotorRunState[motorC] != runStateIdle){}
		motor[motorC] = 0;
		wait1Msec(500);

		return;
}
