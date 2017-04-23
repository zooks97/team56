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
    float temp;
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

    motor[motorA] = 0;
    motor[motorB] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc2, &loc1);
  
    // FILL ME IN WHEN YOU FIND OUT AT THE DEMO  
    loc1.heading = 90; //given 

   // Turn towards A
    if (loc1.x < A.x) { // if on left of A site
        turnToAngle(loc1.heading, 0);
        forward(fabs(loc1.x - A.x), POWSLOW);
        zeroLeft(90, POWSLOW);
    } else { // if on right of A site
        turnToAngle(loc1.heading, 180);
        forward(fabs(loc1.x - A.x), POWSLOW);
        zeroRight(90, POWSLOW);
    }

    // Drive to 5cm away from A
    forward((A.y - loc1.y - 50), POWFAST);
    //drop at A
    droppo();

    /*facing 90, 20cm north of A*/
    zeroRight(90, POWSLOW);

    // move forward to be right above B
    forward((B.x - A.x), POWFAST);
    //face B
    zeroRight(90, POWSLOW);
    //go to B
    forward((A.y + droppoOffset) - B.y - 50, POWMID);
    //drop at B
    droppo();

    //Turn left
    zeroLeft(90, POWSLOW);
    // go forward past obstacle
    forward(3140 - B.x);
    //turn to face south
    zeroRight(90, POWSLOW);
    //move down to C.y
    forward((B.y - droppoOffset - C.y), POWMID);
    //turn towards C
    zeroRight(90, POWSLOW);
    //go near C
    forward(3140 - C.x - 50);
    //drop at C
    droppo();

    //turn to south
    zeroLeft(90, POWSLOW);
    //go down to avoid obstacle
    forward(C.y - 250);
    //face west (homeward)
    zeroRight(90, POWSLOW);
    //go to below home
    forward(C.x - droppoOffset - home.x, POWMID);
    //turn to north
    zeroRight(90, POWSLOW);
    //slide into the dms
    forward(150, POWSLOW - 15);

    motor[motorA] = 0;
    Motor[motorB] = 0;
    displayCenteredTextLine(4, "Ay papi");
}