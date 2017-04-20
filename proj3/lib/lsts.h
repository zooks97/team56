/**** TEAM 56 ****/
// LSTS SYSTEM //
#include "data.h"

#define HEIGHT 80 // mm

void LSTS(location currLoc, location* newLoc){
    word msg;

	wait1Msec(1000);

	while(bQueuedMsgAvailable()){
	  	wait1Msec(1000);
	    ClearMessage();
	    msg = message;
	}

	while(message != 0){
		wait1Msec(1000);
        ClearMessage();
    }

	wait1Msec(1000);
	sendMessage(HEIGHT);
    displayCenteredTextLine(4, "Esperando....");

	while(message == 0){
		wait1Msec(1000);
	}

	newLoc->errorCode = messageParm[0];
	newLoc->x = messageParm[1];
	newLoc->y = messageParm[2];
	newLoc->heading = atan((currLoc.y - newLoc->y) / (currLoc.x - newLoc->x));

	displayCenteredTextLine(0, "X: %d", newLoc->x);
	displayCenteredTextLine(1, "Y: %d", newLoc->y);
    displayCenteredTextLine(2, "Error Code: %d", newLoc->errorCode);

	switch(newLoc->errorCode){
		case 1:
			displayCenteredTextLine(3, "No error.");
			break;
		case 2:
			displayCenteredTextLine(3, "Manual override.");
			break;
		case 4:
			displayCenteredTextLine(3, "Out of bounds.");
			break;
		case 8:
			displayCenteredTextLine(3, "No marker seen.");
			break;
		case 16:
			displayCenteredTextLine(3, "LSTS error.");
			break;
		case 32:
			displayCenteredTextLine(3, "Busy.");
			break;
		default:
			displayCenteredTextLine(3, "Not recognized.");
			break;
	}

	displayCenteredTextLine(4, "");
    wait1Msec(1000);
	ClearMessage();

	while(bQueuedMsgAvailable()){
  	    wait1Msec(1000);
        word temp;
        ClearMessage();
        temp = message;
    }

	while(message != 0){
		wait1Msec(1000);
        ClearMessage();
    }
}

//void LSTS(location *ALV) {
//    float prevX = ALV->x;
//    float prevY = ALV->y;

//    //wait1msec[500]; //doc said to wait

//    sendMessage(HEIGHT); // nMessageID is height off ground in mm
//    wait1Msec(3000);

//    /* Error Codes
//    * 1  No error
//    * 2  Manual override engaged
//    * 4  Out of bounds detected
//    * 8  No ALV marker seen
//    * 16 LSTS system error
//    * 32 Busy - request again later
//    */

//    ALV->errorCode = messageParm[0];
//    ALV->x = messageParm[1];
//    ALV->y = messageParm[2];
//		if (ALV->errorCode > 3) {
//    		ALV->errorThreatLevelMidnight = '!';
//    } else {
//    		ALV->errorThreatLevelMidnight = '$';
//    }
//    ALV->heading = atan((prevY - ALV->y) / (prevX - ALV->x));

//    ClearMessage();

//    if (ALV->errorThreatLevelMidnight == '!') {
//    		LSTS(ALV);
//}
//    return; //ALV;
//}
