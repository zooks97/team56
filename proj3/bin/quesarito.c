#include "../lib/lsts.h"
#include "../lib/droppo.h"
#include "../lib/motion.h"

#define POWSLOW 10
#define POWMID 20
#define POWFAST 30

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
        forward(fabs(loc1.x - A.x), POWSLOW);
        zeroLeft(91, POWSLOW);

    } else { // if on right of A site
        turnToAngle(loc1.heading, 180);
        forward(fabs(loc1.x - A.x), POWSLOW);
        zeroRight(91, POWSLOW);

    }

    // Drive to A
    forward((A.y - loc1.y), POWFAST);

    /*facing 91, 20cm north of A*/
    zeroRight(91, POWSLOW);

    // move forward to be right above B
    forward((B.x - A.x), POWFAST);
    //face B
    zeroRight(91, POWSLOW);
    //go to B
    forward(A.y - B.y, POWMID);

    //Turn left
    zeroLeft(91, POWSLOW);
    // go forward past obstacle
    forward(3140 - B.x);
    //turn to face south
    zeroRight(91, POWSLOW);
    //move down to C.y
    forward((B.y - C.y), POWMID);
    //turn towards C
    zeroRight(91, POWSLOW);
    //go near C
    forward(3140 - C.x);


    //turn to south
    zeroLeft(91, POWSLOW);
    //go down to avoid obstacle
    forward(C.y - 250);
    //face west (homeward)
    zeroRight(91, POWSLOW);
    //go to below home
    forward(C.x - home.x, POWMID);
    //turn to north
    zeroRight(91, POWSLOW);
    //slide into the dms
    forward(150, POWSLOW - 15);


    motor[motorA] = 0;
    motor[motorB] = 0;
    displayCenteredTextLine(4, "Ay papi");
}
