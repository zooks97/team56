#define GOAL 75
#define PGAIN 1.35

task main(){
	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorB] = 0;

	nMotorEncoderTarget[motorA] = GOAL;
	nMotorEncoderTarget[motorB] = GOAL;

	motor[motorA] = 100;
	motor[motorB] = 100;

	while(nMotorRunState[motorB] != runStateIdle){
	    motor[motorA] = motor[motorA] - (PGAIN * (GOAL - theta)); /*P(GOAL - theta)*/ //I(theta') D(theta)
	    motor[motorB] = motor[motorA];
	}
}
