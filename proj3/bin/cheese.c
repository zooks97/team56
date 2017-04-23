#include "../lib/lsts.h"
#include "../lib/droppo.h"
#include "../lib/motion.h"

#define POWSLOW 30
#define POWMID 50
#define POWFAST 70
#define INITHEAD 90
#define RIGHTANGLE 91

task main() {
    location loc1;
    location loc2;
    location A;
    location B;
    location C;
    location home;
    float droppoOffset;

    //mm
    A.x = 340;
    A.y = 2050;
    B.x = 2290;
    B.y = 1470;
    C.x = 2770;
    C.y = 550;
    home.x = 400;
    home.y = 600;

    //mm
    droppoOffset = 200;

    //for heading
    loc2.x = 0;
    loc2.y = 0;

    //stop and get location
    motor[motorA] = 0;
    motor[motorB] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc2, &loc1);

    loc1.heading = INITHEAD;
    // loc1.x = 430;
    // loc1.y = 470;
   
    // Turn towards A
    if (loc1.x < A.x) { // if on left of A site
        turnToAngle(loc1.heading, 0);
        forward(fabs(loc1.x - A.x), POWSLOW);
        zeroLeft(RIGHTANGLE, POWSLOW);
    } else { // if on right of A site
        turnToAngle(loc1.heading, 180);
        forward(fabs(loc1.x - A.x), POWSLOW);
        zeroRight(RIGHTANGLE, POWSLOW);
    }

    // Drive to 5cm away from A
    forward((A.y - loc1.y - 50), POWFAST);
    //drop at A
    droppo();

    /*facing 90, 20cm north of A*/
    zeroRight(RIGHTANGLE, POWSLOW);

    // move forward to be right above B
    forward((B.x - A.x), POWFAST);
    //face B
    zeroRight(RIGHTANGLE, POWSLOW);
    //go to B
    forward((A.y + droppoOffset) - B.y - 50, POWMID);
    //drop at B
    droppo();

    //Turn left
    zeroLeft(RIGHTANGLE, POWSLOW);
    // go forward past obstacle
    forward(3140 - B.x);
    //turn to face south
    zeroRight(RIGHTANGLE, POWSLOW);
    //move down to C.y
    forward((B.y - droppoOffset - C.y), POWMID);
    //turn towards C
    zeroRight(RIGHTANGLE, POWSLOW);
    //go near C
    forward(3140 - C.x - 50);
    //drop at C
    droppo();

    //turn to south
    zeroLeft(RIGHTANGLE, POWSLOW);
    //go down to avoid obstacle
    forward(C.y - 250);
    //face west (homeward)
    zeroRight(RIGHTANGLE, POWSLOW);
    //go to below home
    forward(C.x - droppoOffset - home.x, POWMID);
    //turn to north
    zeroRight(RIGHTANGLE, POWSLOW);
    //slide into the dms
    forward(150, POWSLOW - 15);

    motor[motorA] = 0;
    motor[motorB] = 0;
    displayCenteredTextLine(4, "Ay papi");
}
