/**** TEAM56 ****/
// zeroTurn test//

#include "../lib/motion.h"

#define ANGLE 180
#define X 8
#define Y 1

task main(){

    //this works ok, from testing
    zeroTurn(ANGLE + (ANGLE / 360 * X) - ((1800 - ANGLE) / 360 * Y), 30);

    return;
}
