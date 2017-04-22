#include "../lib/lsts.h"
//#include "../lib/data.h"
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

    A.x = 34;
    A.y = 205;
    B.x = 229;
    B.y = 147;
    C.x = 277;
    C.y = 55;
    home.x = 40;
    home.y = 60;

    loc2.x = 0;
    loc2.y = 0;

    motor[motorA] = 0;
    motor[motorB] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc2, &loc1);
    // FILL ME IN WHEN YOU FIND OUT AT THE DEMO
    loc1.heading = 90;

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
    forward((A.y - loc1.y - 5), POWFAST);

    // FIXME: hallsweep funciton and bin drop //
    //move away  from bin make sure to be far enough to allow for a zeroturn
    droppo();

    motor[motorA] = 0;
    motor[motorB] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    // After drop bin at A, turn to face right
    turnToAngle(loc1.heading, 0);
    // move forward to be right above B
    forward((B.x - loc1.x), POWFAST);
    // Check heading
    motor[motorA] = 0;
    motor[motorB] = 0;
    playImmediateTone(4400, 2);
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
        // I'm not sure that this is what I want




















    }
    forward((sqrt(pow((B.x - loc1.x), 2.0) + pow((B.y - loc1.y), 2.0))) - 5, POWMID);

    // FIXME hallsweep to drop to move away
    droppo();

    motor[motorA] = 0;
    motor[motorB] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    //Turn to right
    turnToAngle(loc1.heading, 0);
    // go forward past obstacle
    forward((319 - loc1.x), POWMID);

    zeroRight(90, POWSLOW);
    forward((loc1.y - C.y), POWMID);

    // Check location
    motor[motorA] = 0;
    motor[motorB] = 0;
    playImmediateTone(4400, 2);
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
        // Still not sure that this logic is right
















    }
    forward((sqrt(pow((C.x - loc1.x), 2.0) + pow((C.y - loc1.y), 2.0))) - 5, POWMID);

    // FIXME sweep to drop to move away
    droppo();

    // Check location
    motor[motorA] = 0;
    motor[motorB] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    // Face downward
    turnToAngle(loc1.heading, 270);
    forward((loc1.y - 25), POWMID);

    // Face left
    zeroRight(90, POWSLOW);
    forward((loc1.x - 179), POWMID);
    // Check me ^

























    //Home in on the base
    // Check location
    motor[motorA] = 0;
    motor[motorB] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(10, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    // Go towards home
    temp = atand(fabs(home.y - loc1.y) / fabs(home.x - loc1.x));
    zeroRight(temp, POWSLOW);
    forward((sqrt(pow((home.x - loc1.x), 2.0) + pow((home.y - loc1.y), 2.0))), POWFAST);

    motor[motorA] = 0;
    Motor[motorB] = 0;
    displayCenteredTextLine(4, "Ay papi");
}
