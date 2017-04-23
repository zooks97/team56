#include "../lib/lsts.h"
#include "../lib/droppo.h"
#include "../lib/motion.h"

#define POWSLOW 30
#define POWMID 50
#define POWFAST 70

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
    B.x = 2291;
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
        turnToAngle(loc1.heading, 0);
        wait1Msec(500);
        forward(fabs(loc1.x - A.x), POWSLOW);
        wait1Msec(500);
        zeroLeft(91, POWSLOW);
        wait1Msec(500);
    } else { // if on right of A site
        turnToAngle(loc1.heading, 180);
        wait1Msec(500);
        forward(fabs(loc1.x - A.x), POWSLOW);
        wait1Msec(500);
        zeroRight(91, POWSLOW);
        wait1Msec(500);
    }

    // Drive to A
    forward((A.y - loc1.y), POWFAST);
    wait1Msec(500);

    /*facing 91, 20cm north of A*/
    zeroRight(91, POWSLOW);
    wait1Msec(500);

    // move forward to be right above B
    forward((B.x - A.x), POWFAST);
    wait1Msec(500);
    //face B
    zeroRight(91, POWSLOW);
    wait1Msec(500);
    //go to B
    forward(A.y - B.y, POWMID);
    wait1Msec(500);

    //Turn left
    zeroLeft(91, POWSLOW);
    wait1Msec(500);
    // go forward past obstacle
    forward(3140 - B.x);
    wait1Msec(500);
    //turn to face south
    zeroRight(91, POWSLOW);
    wait1Msec(500);
    //move down to C.y
    forward((B.y - C.y), POWMID);
    wait1Msec(500);
    //turn towards C
    zeroRight(91, POWSLOW);
    wait1Msec(500);
    //go near C
    forward(3140 - C.x);
    wait1Msec(500);

    //turn to south
    zeroLeft(91, POWSLOW);
    wait1Msec(500);
    //go down to avoid obstacle
    forward(C.y - 250);
    wait1Msec(500);
    //face west (homeward)
    zeroRight(91, POWSLOW);
    wait1Msec(500);
    //go to below home
    forward(C.x - home.x, POWMID);
    wait1Msec(500);
    //turn to north
    zeroRight(91, POWSLOW);
    wait1Msec(500);
    //slide into the dms
    forward(150, POWSLOW - 15);
    wait1Msec(500);

    motor[motorA] = 0;
    motor[motorB] = 0;
    displayCenteredTextLine(4, "Ay papi");
}
