/**** TEAM 56 ****/
// DATA MANAGEMENT //

#define SCALEMAX 7.0
#define SCALEMIN 0.0

typedef struct{
    float x;
    float y;
    float heading;
    int errorCode;
    char errorThreatLevelMidnight;
} location;

////scales hall values linearly
//short hallScale(int raw){
//    if (raw > HALLMAX){
//        return 7;
//    }else if(raw < HALLMIN){
//        return 0;
//    }else{
//        return (raw - HALLMIN) *
//        (SCALEMAX - SCALEMIN) / (HALLMAX - HALLMIN)
//        + SCALEMIN;
//    }
//}

int hallValue(port){
    int val = sensorValue[port];
