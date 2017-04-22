#include "../lib/antenna.h"
#include "../lib/motion.h"
#define NUMBINS 3

task main() {
    int i = 0;
    while (i < NUMBINS) {
        drop();
        forward(100, 20);
        i++;
    }
}
