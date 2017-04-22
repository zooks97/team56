#include "../lib/antenna.h"
#define NUMBINS 3

task main() {
    int i = 0;
    while (i < NUMBINS) {
        drop();
        forward(10, 20);
    }
}