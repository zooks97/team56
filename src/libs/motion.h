/*  STANDARDS
 * return functName(args){
 *      blah
 *  }
 *
 * DISTANCE UNIT    mm
 * ANGLE UNIT       deg
 * SPEED UNIT       mm / s
 * TIME UNIT        s
 *
 * motorA   right
 * motorB   left
 *
 *
 *
 *
 * define all constants in preprocessor
 * make function prototypes
 * use code standard
 * comment heavily
*/

#define RWHL 56 //mm
#define RRBT 85 //mm
#define DEGMM (4.3/3.0) //degrees per mm
#define BASESPEED 60;

void straight(float dist);
void zeroTurn(float angle);
void movingTurn(float radius);

//move straight for dist mm
void straight(float dist){ //, float speed){
    int deg = DEGMM * dist; //degree value given to the motors
    float error;            //error value between motors
    float pGain = 3;        //proportional gain

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
        motor[motorA] = -(pGain * error / 2) + BASESPEED;
        motor[motorB] =  (pGain * error / 2) + BASESPEED;
    }
}

//negative angle to turn DIR
//positive angle to turn DIR
//works a lot like the straight function,
//just reverses the directions of the motors
void zeroTurn(float angle){ //, float speed){
    float error;
    float pGain = 3;
    nMotorEncoder[motorA] = 0;
    nMotorEncoder[motorB] = 0;

    while(nMotorEncoder[motorB] > -angle){
        error = nMotorEncoder[motorA] + nMotorEncoder[motorB];
        motor[motorA] =  (pGain * error / 2) + BASESPEED;
        motor[motorB] = -(pGain * error / 2) - BASESPEED;
    }
}

//negative radius to turn right
//positive radius to turn left
//speed in mm/s (it'll be converted to angle/s)
//radius in mm
//angle in deg
void movingTurn(float radius, float angle){ //, float speed){
    /* should be able to make the robot act like
       it's going around a circle of the given radius
       at the given speed in mm/s
    */
    float inRadius = radius - RRBT;
    float outRadius = radius + RRBT;

    float inArc = (2 * PI * inRadius) * (angle / 360);
    float outArc = (2 * PI * outRadius) * (angle / 360);

    float ratio = inArc / outArc;

    float speed = BASESPEED;

    float inSpeed = speed;
    float outSpeed = speed * ratio;

    float deg = outArc * DEGMM;

    nMotorEncoder[motorA] = 0;
    nMotorEncoder[motorB] = 0;

    //turn right
    if(radius > 0){
        while(nMotorEncoder[motorB] < deg){
            motor[motorA] = outSpeed;
            motor[motorB] = inSpeed;
        }
    //turn left
    }else{
        while(nMotorEncoder[motorA] < deg){
            motor[motorA] = inSpeed;
            motor[motorB] = outSpeed;
        }
    }
}