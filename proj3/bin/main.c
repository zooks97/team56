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

    A.x = 340;
    A.y = 2050;
    B.x = 2290;
    B.y = 1470;
    C.x = 2770;
    C.y = 550;
    home.x = 400;
    home.y = 600;

    loc2.x = 0;
    loc2.y = 0;

    motor[motorB] = 0;
    motor[motorC] = 0;
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
    forward((A.y - loc1.y - 50), POWFAST);

    droppo();

    motor[motorB] = 0;
    motor[motorC] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(100, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    // After drop bin at A, turn to face right
    turnToAngle(loc1.heading, 0);
    // move forward to be right above B
    forward((B.x - loc1.x), POWFAST);
    // Check heading
    motor[motorB] = 0;
    motor[motorC] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(100, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    //turn to face B
    temp = atan(fabs(B.x - loc1.x) / fabs(B.y - loc1.y)) / PI * 180;
    if (loc1.x > B.x) {
        zeroRight((90 + temp), POWSLOW);
    } else {
        zeroRight((temp - 90), POWSLOW);
    }
    forward((sqrt(pow((B.x - loc1.x), 2.0) + pow((B.y - loc1.y), 2.0))) - 50, POWMID);

    droppo();

    motor[motorB] = 0;
    motor[motorC] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(100, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    //Turn to right
    turnToAngle(loc1.heading, 0);
    // go forward past obstacle
    forward((3190 - loc1.x), POWMID);

    zeroRight(90, POWSLOW);
    forward((loc1.y - C.y), POWMID);

    // Check location
    motor[motorB] = 0;
    motor[motorC] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(100, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    // Go towards C
    temp = atan(fabs(C.y - loc1.y) / fabs(C.x - loc1.x)) / PI * 180;
    if (loc1.y < C.y) {
        zeroRight((90 + temp), POWSLOW);
    } else {
        zeroRight((temp - 90), POWSLOW);
    }
    forward((sqrt(pow((C.x - loc1.x), 2.0) + pow((C.y - loc1.y), 2.0))) - 5, POWMID);

    droppo();

    // Check location
    motor[motorB] = 0;
    motor[motorC] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(100, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    // Face downward
    turnToAngle(loc1.heading, 270);
    forward((loc1.y - 2500), POWMID);

    // Face left
    zeroRight(90, POWSLOW);
    forward((loc1.x - 1790), POWMID);

    //Home in on the base
    // Check location
    motor[motorB] = 0;
    motor[motorC] = 0;
    playImmediateTone(4400, 2);
    LSTS(loc1, &loc2);
    forward(100, POWSLOW);
    wait1Msec(15000);
    LSTS(loc2, &loc1);

    // Go towards home
    temp = atan(fabs(home.y - loc1.y) / fabs(home.x - loc1.x)) / PI * 180;
    zeroRight(temp, POWSLOW);
    forward((sqrt(pow((home.x - loc1.x), 2.0) + pow((home.y - loc1.y), 2.0))), POWFAST);

    motor[motorB] = 0;
    Motor[motorC] = 0;
    displayCenteredTextLine(4, "Ay papi");
}