/**** TEAM 56 ****/
// DATA MANAGEMENT //

#define SCALEMAX 7.0
#define SCALEMIN 0.0

typedef struct{
    float x = 0;
    float y = 0;
    float heading = 0;
    int errorCode = 0;
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
