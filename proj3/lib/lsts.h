/**** TEAM 56 ****/
// LSTS SYSTEM //

<<<<<<< HEAD
=======
//struct
    //command
    //variable 1
    //variable 2
    //variable n

typedef struct{
    float x;
    float y;
    float height;
    float heading;
    int errorCode;
} location;

>>>>>>> origin/master
location LSTS(location ALV) {
    prevX = ALV.x
    prevY = ALV.y
    
    wait1msec[500]; //doc said to wait

    sendMessage(ALV.height); // nMessageID is height off ground in mm
    wait1msec[3000];
    
    ALV.errorCode = messageParm[0];
    ALV.x = messageParm[1];
    ALV.y = messageParm[2];
    
    ALV.heading = atan((prevy - ALV.y) / (prevX - ALV.x));
    
    ClearMessage();
    return ALV;
}    