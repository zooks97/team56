#include "../lib/lsts.h"
#include "../lib/data.h"

task main() {
    location newLoc;
    location currLoc;

    currLoc.x = 0;
    currLoc.y = 0;

    LSTS(currLoc, &newLoc);

    return;
}
