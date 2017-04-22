/**** TEAM 56 ****/
// Demonstration //

#include "../lib/motion.h"
#include "../lib/data.h"
#include "../lib/lsts.h"
#include "../lib/bin.h"
#include "../lib/sensor.h"

task main(){
    location currLoc;
    location newLoc
    currLoc.x = 0;
    currLoc.y = 0;
    
    LSTS(currLoc, *newLoc);
    forward(10, 30);
    
    LSTS(currLoc, *newLoc);
}
