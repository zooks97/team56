/**** TEAM 56 ****/
// LSTS SYSTEM //

//struct
    //command
    //variable 1
    //variable 2
    //variable n
#define HEIGHT 80 // mm

void LSTS(location *ALV) {
    float prevX = ALV->x;
    float prevY = ALV->y;

    //wait1msec[500]; //doc said to wait

    sendMessage(HEIGHT); // nMessageID is height off ground in mm
    wait1Msec(3000);

    /* Error Codes
    * 1  No error
    * 2  Manual override engaged
    * 4  Out of bounds detected
    * 8  No ALV marker seen
    * 16 LSTS system error
    * 32 Busy - request again later
    */

    ALV->errorCode = messageParm[0];
    ALV->x = messageParm[1];
    ALV->y = messageParm[2];
		if (ALV->errorCode > 3) {
    		ALV->errorThreatLevelMidnight = '!';
    } else {
    		ALV->errorThreatLevelMidnight = '$';
    }
    ALV->heading = atan((prevY - ALV->y) / (prevX - ALV->x));

    ClearMessage();

    if (ALV->errorThreatLevelMidnight == '!') {
    		LSTS(ALV);
}
    return; //ALV;
}
