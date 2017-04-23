/**** TEAM 56 ****/
// MOTION FUNCTIONS //

/*
 * DISTANCE UNIT    mm
 * ANGLE UNIT       deg
 * SPEED UNIT       mm / s
 * TIME UNIT        s
 *
 * motorB   right
 * motorC   left
 *
*/

#define RWHL          40.8 //mm
#define RRBT          85.0 //mm

void turnToAngle(float currAngle, float desAngle);
void forward(float dist, float pow);
void zeroLeft(float angle, float pow);
void zeroRight(float angle, float pow);
//void backward(float dist, float pow);
//void movingLeft(float radius, float angle, float pow);
//void movingRight(float radius, float angle, float pow);

void turnToAngle(float currAngle, float desAngle) {
    float dAngle = currAngle - desAngle;
    if ((dAngle <= 180) && (dAngle > 0)) {
        zeroRight(dAngle, 30);
    } else if (dAngle > 180) {
        zeroLeft((360 - dAngle), 30);
    } else if (dAngle > -180) {
        zeroLeft(fabs(dAngle), 30);
    } else {
        zeroRight((360 + dAngle), 30);
    }

    return;
}

void forward(float dist, float pow){
    //float error;            //error value between motors
    //float pGain = 3;        //proportional gain;
    int deg = dist * 360 / (2 * PI * RWHL);

    //zero the motor encoders
    nMotorEncoder[motorB] = 0;
    nMotorEncoder[motorC] = 0;

    //set targets
    nMotorEncoderTarget[motorB] = deg;
    nMotorEncoderTarget[motorC] = deg;

    //start motors
    motor[motorB] = pow;
    motor[motorC] = pow;

    //run motors
    while(nMotorRunState[motorB] != runStateIdle){}

    //stop motors
    motor[motorB] = 0;
    motor[motorC] = 0;

    wait1Msec(500);

    // //checks to see if the motor has travelled the required
    // //number of degrees (rotations)
    // while(nMotorEncoder[motorB] < deg){
    //     //error is the difference between how many degrees
    //     //each motor has travelled
    //     error = nMotorEncoder[motorB] - nMotorEncoder[motorC];
    //     //adjust the speed of each motor from the base speed
    //     //proportionally to half the error (each motor tries
    //     //to correct for half the error
    //     motor[motorB] = -(pGain * error / 2) + pow;
    //     motor[motorC] = (pGain * error / 2) + pow;
    // }

    return;
}

void zeroLeft(float angle, float pow){
    nMotorEncoder[motorB] = 0;
    nMotorEncoder[motorC] = 0;

    nMotorEncoderTarget[motorC] = RRBT / RWHL * angle;
    nMotorEncoderTarget[motorB] = -RRBT / RWHL * angle;

    motor[motorB] = pow;
    motor[motorC] = -pow;

    while(nMotorRunState[motorC] != runStateIdle){}

    motor[motorB] = 0;
    motor[motorC] = 0;

    return;
}

void zeroRight(float angle, float pow){
    nMotorEncoder[motorB] = 0;
    nMotorEncoder[motorC] = 0;

    nMotorEncoderTarget[motorB] = RRBT / RWHL * angle;
    nMotorEncoderTarget[motorC] = -RRBT / RWHL * angle;

    motor[motorC] = pow;
    motor[motorB] = -pow;

    while(nMotorRunState[motorB] != runStateIdle){}

    motor[motorB] = 0;
    motor[motorC] = 0;

    return;
}

//move straight back for dist mm
//void backward(float dist, float pow){
//    float error;            //error value between motors
//    float pGain = 3;        //proportional gain;
//    int deg = dist * 360 / (2 * PI * RWHL);

//    //zero the motor encoders
//    nMotorEncoder[motorA] = 0;
//    nMotorEncoder[motorB] = 0;

//    //checks to see if the motor has travelled the required
//    //number of degrees (rotations)
//    while(nMotorEncoder[motorA] > deg){
//        //error is the difference between how many degrees
//        //each motor has travelled
//        error = nMotorEncoder[motorA] - nMotorEncoder[motorB];
//        //adjust the speed of each motor from the base speed
//        //proportionally to half the error (each motor tries
//        //to correct for half the error
//        motor[motorA] = (pGain * error / 2) + pow;
//        motor[motorB] = -(pGain * error / 2) + pow;
//    }
//    motor[motorA] = 0;
//    motor[motorB] = 0;
//    return;
//}

//void zeroLeft(float angle, float pow){
//    //float error;
//    //float pGain = 0.1;
//    nMotorEncoder[motorB] = 0;
//    nMotorEncoder[motorC] = 0;

//    //this equation was created from testing using an input angle
//    //of 1800 (see the y term)
//    short x = 8;
//    short y = 1;
//    angle = angle + (angle / 360 * x) - ((1800 - angle) / 360 * y);

//    //convert to robot degrees
//    angle = RRBT / RWHL * angle;

//        while(nMotorEncoder[motorB] > -angle){
//	        //error = nMotorEncoder[motorA] + nMotorEncoder[motorB];
//	        //motor[motorA] =  (pGain * error / 2) + pow;
//	        //motor[motorB] = -(pGain * error / 2) - pow;
//	        //error = 0;
//	        motor[motorC] = pow;
//	        motor[motorB] = -pow;
//        }

//    motor[motorB] = 0;
//    motor[motorC] = 0;

//    return;
//}

//void zeroRight(float angle, float pow){
//    //float error;
//    //float pGain = 0.1;
//    nMotorEncoder[motorB] = 0;
//    nMotorEncoder[motorC] = 0;

//    //this equation was created from testing using an input angle
//    //of 1800 (see the y term)
//    //short x = 8;
//    //short y = 1;
//    //angle = angle + (angle / 360 * x) - ((1800 - angle) / 360 * y);

//    //convert to robot degrees
//    angle = RRBT / RWHL * angle;

//    while(nMotorEncoder[motorC] > -angle){
//        //error = nMotorEncoder[motorA] + nMotorEncoder[motorB];
//        //motor[motorA] =  (pGain * error / 2) + pow;
//        //motor[motorB] = -(pGain * error / 2) - pow;
//        //error = 0;
//        motor[motorB] = pow;
//        motor[motorC] = -pow;
//    }

//    motor[motorB] = 0;
//    motor[motorC] = 0;
//    return;
//}

//void movingLeft(float radius, float angle, float pow){
//    /* should be able to make the robot act like
//       it's going around a circle of the given radius
//       at the given speed in mm/s
//    */
//    //pow = powScale(pow);
//    float inRadius = radius - RRBT;
//    float outRadius = radius + RRBT;

//    //float inArc = (2 * PI * inRadius) * (angle / 360);
//    float outArc = (2 * PI * outRadius) * (angle / 360);

//    //float ratio = inArc / outArc;

//    float inPow = pow;
//    float outPow = pow * outRadius / inRadius;

//    float deg = outArc * DEGMM;

//    nMotorEncoder[motorA] = 0;
//    nMotorEncoder[motorB] = 0;


//    while(nMotorEncoder[motorA] < deg){
//        motor[motorA] = outPow;
//        motor[motorB] = inPow;
//    }

//    motor[motorA] = 0;
//    motor[motorB] = 0;
//    return;
//}

//void movingRight(float radius, float angle, float pow){
//    /* should be able to make the robot act like
//       it's going around a circle of the given radius
//       at the given speed in mm/s
//    */
//    //pow = powScale(pow);
//    float inRadius = radius - RRBT;
//    float outRadius = radius + RRBT;

//    //float inArc = (2 * PI * inRadius) * (angle / 360);
//    float outArc = (2 * PI * outRadius) * (angle / 360);

//    //float ratio = inArc / outArc;

//    float inPow = pow;
//    float outPow = pow * outRadius / inRadius;

//    float deg = outArc * DEGMM;

//    nMotorEncoder[motorA] = 0;
//    nMotorEncoder[motorB] = 0;


//    while(nMotorEncoder[motorA] < deg){
//        motor[motorA] = inPow;
//        motor[motorB] = outPow;
//    }

//    motor[motorA] = 0;
//    motor[motorB] = 0;
//    return;
//}