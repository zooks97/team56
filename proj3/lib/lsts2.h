#include "data.h"
#include <math.h>
#define HEIGHT 80 //mm

location lsts(location currLoc){
    location newLoc;
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

	newLoc.errorCode = messageParm[0];
	newLoc.x = messageParm[1];
	newLoc.y = messageParm[2];
	newLoc.heading = atan((currLoc.y - newLoc.y) / (currLoc.x - newLoc.x));

	displayCenteredTextLine(0, "X: %d", newLoc.x);
	displayCenteredTextLine(1, "Y: %d", newLoc.y);
    displayCenteredTextLine(2, "Error Code: %d", errorCode);

	switch(err){
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

    return newLoc;
}
