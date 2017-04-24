/**** TEAM56 ****/
// zeroTurn test//

#include "../lib/motion.h"

#define ANGLE 180
#define X 8
#define Y 1
//ANGLE + (ANGLE / 360 * X) - ((1800 - ANGLE) / 360 * Y)
task main(){

    //this works ok, from testing
    zeroRight(95.2, 30);
    //zeroLeft(91, 30);

    return;
}
