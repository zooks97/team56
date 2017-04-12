/**** TEAM 56 ****/
// SENSOR FUNCTIONS //
#define HALLPORT S1
#define HALLMAX 600//800
#define HALLMIN 470//400

short hallSensor();

short hallSensor(){
    return (((SensorValue[HALLPORT] - HALLMIN) / (HALLMAX - HALLMIN)) * 100);
}
