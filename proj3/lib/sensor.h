/**** TEAM 56 ****/
// SENSOR FUNCTIONS //
#define HALLPORT 1
#define HALLMAX 800
#define HALLMIN 400

short hallSensor();

short hallSensor(){
    return (((sensorValue[HALLPORT] - HALLMIN) / (HALLMAX - HALLMIN)) * 100);
}
