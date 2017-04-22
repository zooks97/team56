/**** TEAM 56 ****/
// SENSOR FUNCTIONS //
#define HALLPORT1 S1
#define HALLPORT2 S2
#define HALLMAX 600//800
#define HALLMIN 470//400

short hallSensor();

short hallSensor(){
    if (SensorValue[HALLPORT1] > SensorValue[HALLPORT2]) {
        return (((SensorValue[HALLPORT1] - HALLMIN) / (HALLMAX - HALLMIN)) * 100);
    } else {
        return (((SensorValue[HALLPORT2] - HALLMIN) / (HALLMAX - HALLMIN)) * 100);
    }
}