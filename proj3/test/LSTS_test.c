#include "../lib/lsts.h"
#include "../lib/data.h"

#define POWSLOW 30
#define POWMID 50
#define POWFAST 70

task main() {
    location loc1;
    location loc2;
    location A;
    location B;
    location C;
    float temp;
    
    A.x = 55;
    A.y = 220;
    B.x = 250;
    B.y = 162;
    C.x = 298;
    C.y = 70;

    loc1.x = 0;
    loc1.y = 0;

    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);
   
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
    
    forward((A.y - loc1.y - 5), POWFAST);
    
    // FIXME: hallsweep funciton and bin drop //
    //move away  from bin make sure to be far enough to allow for a zeroturn
    
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);
    
    // After drop bin at A, turn to face right
    turnToAngle(loc1.heading, 0);
    // move forward to be right above B
    forward((B.x - loc1.x), POWFAST);
    // Check heading
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);
    
    //turn to face B
    temp = atand(fabs(B.x - loc1.x) / fabs(B.y - loc1.y));
    if (loc1.x > B.x) {
        zeroRight((90 + temp), POWSLOW);
    } else {
        zeroRight((temp - 90), POWSLOW);
    }
    forward((sqrt(pow((B.x - loc1.x), 2.0) + pow((B.y - loc1.y), 2.0))) - 5, POWMID);
    
    // FIXME hallsweep to drop to move away
    
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);
    
    //Turn to right
    turnToAngle(loc1.heading, 0);
    // go forward past obstacle
    forward((340 - loc1.x), POWMID);
    
    zeroRight(90, POWSLOW);
    forward((loc1.y - C.y), POWMID);
    
    // Check location
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);
    
    // Go towards C
    temp = atand(fabs(C.y - loc1.y) / fabs(C.x - loc1.x));
    if (loc1.y < C.y) {
        zeroRight((90 + temp), POWSLOW);
    } else {
        zeroRight((temp - 90), POWSLOW);
    }
    forward((sqrt(pow((C.x - loc1.x), 2.0) + pow((C.y - loc1.y), 2.0))) - 5, POWMID);
    
    // FIXME sweep to drop to move away
    
    // Check location
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);
    
    // Face downward
    turnToAngle(loc1.heading, 270);
    forward((loc1.y - 40), POWMID);
    
    // Face left
    zeroRight(90, POWSLOW);
    forward((loc1.x - 240), POWMID);
    
    //Home in on the base
    // Check location
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);
    
    // Go towards home
    temp = atand(fabs(home.y - loc1.y) / fabs(home.x - loc1.x));
    zeroRight(temp, POWSLOW);
    forward((sqrt(pow((home.x - loc1.x), 2.0) + pow((home.y - loc1.y), 2.0))), POWFAST);
    
    nMotor[motorA] = 0;
    nMotor[motorB] = 0;
    displayCenteredTextLine(4, "Ay papi");
}
