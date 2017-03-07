#define VOLTMAX 7.5

float powScale(float pow) {
    float voltageBatt = nImmediateBatteryLevel;

    pow *= VOLTMAX / voltageBatt;

    return pow;
}
