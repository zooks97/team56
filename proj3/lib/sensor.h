/**** TEAM 56 ****/
// SENSOR FUNCTIONS //
#define HALLPORT1 S1
#define HALLPORT2 S2
#define HALLMAX 600//800
#define HALLMIN 470//400

short hallSensor();

short hallSensor(){
    short sens1 = SensorValue[HALLPORT1];
    short sens2 = SensorValue[HALLPORT2] / 10;
    if (sens1 > sens2) {
        return (((sens1 - HALLMIN) / (HALLMAX - HALLMIN)) * 100);
    } else {
        return (((sens2 - HALLMIN) / (HALLMAX - HALLMIN)) * 100);
    }
}