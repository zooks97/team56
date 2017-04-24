#include "../lib/lsts.h"
#include "../lib/droppo.h"
#include "../lib/motion.h"

#define POWSLOW 10
#define POWMID 20
#define POWFAST 30
#define RIGHTANGLE 96

task main() {
    location loc1;
    location loc2;
    location A;
    location B;
    location C;
    location home;
    float droppoOffset;

    A.x = 340;
    A.y = 2050;
    B.x = 2290;
    B.y = 1470;
    C.x = 2770;
    C.y = 550;
    home.x = 400;
    home.y = 600;

    droppoOffset = 200;

    loc2.x = 0;
    loc2.y = 0;

    //motor[motorA] = 0;
    //motor[motorB] = 0;
    //playImmediateTone(4400, 2);
    //LSTS(loc2, &loc1);

    // FILL ME IN WHEN YOU FIND OUT AT THE DEMO
    loc1.heading = 90; //given
    loc1.x = 430;
    loc1.y = 470;
   // Turn towards A
    if (loc1.x < A.x) { // if on left of A site
        //turnToAngle(loc1.heading, 0);
        zeroRight(90, POWMID);
        forward(fabs(loc1.x - A.x + 10), POWMID);
        zeroLeft(RIGHTANGLE, POWMID);

    } else { // if on right of A site
        //turnToAngle(loc1.heading, 180);
        zeroLeft(90, POWMID);
        forward(fabs(loc1.x - A.x + 10), POWMID);
        zeroRight(RIGHTANGLE, POWMID);

    }

    // Drive to A
    forward((A.y - loc1.y), POWFAST);

    motor[motorB] = 0;
    motor[motorA] = 0;
    wait1Msec(500);

    /*facing 91, 20cm north of A*/
    zeroRight(RIGHTANGLE , POWMID);

    // move forward to be right above B
    forward((B.x - A.x), POWFAST);
    //face B
    zeroRight(RIGHTANGLE, POWMID);
    //go to B
    forward(A.y - B.y + 100, POWMID);

    motor[motorB] = 0;
    motor[motorA] = 0;
    wait1Msec(500);

    //Turn left
    zeroLeft(RIGHTANGLE , POWMID);
    // go forward past obstacle
    forward(3070 - B.x, POWFAST);

    motor[motorB] = 0;
    motor[motorA] = 0;
    wait1Msec(500);

    //turn to face south
    zeroRight(RIGHTANGLE + 5 , POWMID);
    //move down to C.y
    forward((B.y - C.y), POWMID);

    motor[motorB] = 0;
    motor[motorA] = 0;
    wait1Msec(500);

    //turn towards C
    zeroRight(RIGHTANGLE , POWMID);
    //go near C
    forward(3140 - C.x, POWFAST);

    motor[motorB] = 0;
    motor[motorA] = 0;
    wait1Msec(500);

    //turn to south
    zeroLeft(RIGHTANGLE, POWMID);
    //go down to avoid obstacle
    forward(C.y - 250, POWFAST);
    //face west (homeward)
    zeroRight(RIGHTANGLE, POWMID);
    //go to below home
    forward(C.x - home.x, POWMID);
    //turn to north
    zeroRight(RIGHTANGLE, POWMID);
    //slide into the dms
    forward(200, POWMID);


    motor[motorA] = 0;
    motor[motorB] = 0;
    displayCenteredTextLine(4, "Ay papi");

    return;
}
