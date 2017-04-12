/**** TEAM 56 ****/
// PoC Task 6 //

#include "../lib/data.h"
#include "../lib/lsts.h"

task main(){
    //request coordinates
		location ALV;
		ALV.x = 0;
		ALV.y = 0;
		LSTS(ALV);
    displayString(1, "(%f, %f)", ALV.x, ALV.y);
    displayString(2, "Error Code: %i", ALV.errorCode);
    if (ALV.errorThreatLevelMidnight == '$') {
    		displayString(3, "Sys Perf n/a");
    } else {
    		displayString(3, "Sys Perf aff");
    }
		//parse coordinates

    //sanity check

    //display coordinates

    //display error(s) or lack thereof
    return;
}
