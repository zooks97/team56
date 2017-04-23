/**** TEAM 56 ****/
// DROPOFF SYSTEM //
#include "./antenna.h"
#include "./motion.h"
#include "./sensor.h"

void droppo();

void droppo() {
    // While you're far away from the magnet, drive slowly forward
    while (hallSensor()) {
        motor[motorB] = 10;
        motor[motorC] = 10;
    }

    // Stop and wait
    motor[motorB] = 0;
    motor[motorC] = 0;
    wait1Msec(1000);
    
    forward(100, 20); /*crawl forward*/
    drop();
    forward(100, 20); /*move away*/

    return;
}
