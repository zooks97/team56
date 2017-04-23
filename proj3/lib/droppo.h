/**** TEAM 56 ****/
// DROPOFF SYSTEM //
#include "lsts.h"
#include "antenna.h"

void droppo();

void droppo() {
    // While you're far away from the magnet, drive slowly forward
    while (hallSensor() < 95) {
      motor[motorA] = 10;
      motor[motorB] = 10;
    }

    // Stop and wait
    motor[motorA] = 0;
    motor[motorB] = 0;
    wait1Msec(500);

    // Crawl forward
    forward(100, 10);
    
    drop();
    
    // Move away
    forward(100, 20);
    
    return;
}