/**** TEAM 56 ****/
// MOTION FUNCTIONS //

/*
 * DISTANCE UNIT    mm
 * ANGLE UNIT       deg
 * SPEED UNIT       mm / s
 * TIME UNIT        s
 *
 * motorA   right
 * motorB   left
 *
*/

#define RWHL          40.8 //mm
#define RRBT           85.0 //mm
#define DEGMM       1 //(4.3/3.0) //degrees per mm

void straight(float dist, float pow);
void zeroTurn(float angle, float pow);
void movingTurn(float radius, float angle, float pow);

//move straight for dist mm
void straight(float dist, float pow){
    float error;            //error value between motors
    float pGain = 3;        //proportional gain;
    int deg = dist * 360 / (2 * PI * RWHL);

    //zero the motor encoders
    nMotorEncoder[motorA] = 0;
    nMotorEncoder[motorB] = 0;

    //checks to see if the motor has travelled the required
    //number of degrees (rotations)
    while(nMotorEncoder[motorA] < deg){
        //error is the difference between how many degrees
        //each motor has travelled
        error = nMotorEncoder[motorA] - nMotorEncoder[motorB];
        //adjust the speed of each motor from the base speed
        //proportionally to half the error (each motor tries
        //to correct for half the error
        motor[motorA] = -(pGain * error / 2) + pow;
        motor[motorB] =  (pGain * error / 2) + pow;
    }
    motor[motorA] = 0;
    motor[motorB] = 0;
    return;
}

//FIXME//
//DOES NOT WORK FOR NEGATIVE ANGLE//
//FIX SO THAT DIRECTION CAN BE CHOSEN//
void zeroTurn(float angle, float pow){
    //float error;
    //float pGain = 0.1;
    nMotorEncoder[motorA] = 0;
    nMotorEncoder[motorB] = 0;

    //this equation was created from testing using an input angle
    //of 1800 (see the y term)
    short x = 8;
    short y = 1;
    angle = angle + (angle / 360 * x) - ((1800 - angle) / 360 * y);

    //convert to robot degrees
    angle = RRBT / RWHL * angle;

    if(angle > 0){
        while(nMotorEncoder[motorB] > -angle){
            //error = nMotorEncoder[motorA] + nMotorEncoder[motorB];
            //motor[motorA] =  (pGain * error / 2) + pow;
            //motor[motorB] = -(pGain * error / 2) - pow;
            //error = 0;
            motor[motorA] = pow;
            motor[motorB] = -pow;
        }
    }else{
            while(nMotorEncoder[motorA] > -angle){
            //error = nMotorEncoder[motorA] + nMotorEncoder[motorB];
            //motor[motorA] =  (pGain * error / 2) + pow;
            //motor[motorB] = -(pGain * error / 2) - pow;
            //error = 0;
            motor[motorB] = pow;
            motor[motorA] = -pow;
        }
    }

    motor[motorA] = 0;
    motor[motorB] = 0;
    return;
}

//FIXME//
//CHANGE SO THAT SIGN OF ANGLE DETERMINES DIRECTION//
//NOT SIGN OF RADIUS//
void movingTurn(float radius, float angle, float pow){
    /* should be able to make the robot act like
       it's going around a circle of the given radius
       at the given speed in mm/s
    */
    //pow = powScale(pow);
    float inRadius = radius - RRBT;
    float outRadius = radius + RRBT;

    float inArc = (2 * PI * inRadius) * (angle / 360);
    float outArc = (2 * PI * outRadius) * (angle / 360);

    //float ratio = inArc / outArc;

    float inPow = pow;
    float outPow = pow * outRadius / inRadius;

    float deg = outArc * DEGMM;

    nMotorEncoder[motorA] = 0;
    nMotorEncoder[motorB] = 0;

    //turn right
    if(radius > 0){
        while(nMotorEncoder[motorB] < deg){
            motor[motorA] = outPow;
            motor[motorB] = inPow;
        }
    //turn left
    }else{
        while(nMotorEncoder[motorA] < deg){
            motor[motorA] = inPow;
            motor[motorB] = outPow;
        }
    }
    motor[motorA] = 0;
    motor[motorB] = 0;
    return;
}
