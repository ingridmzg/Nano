#include "utilities.h"
#include <random>

// 5b) The function returns a random number between the lower and the upper limit.
int randomWithLimits(int lowerLimit, int upperLimit) {
    random_device rd; // seed, obtain a random number from hardware
    default_random_engine generator(rd()); // seed the generator
    uniform_int_distribution<int> distribution(lowerLimit, upperLimit); // define the range

    double number = distribution(generator);
    return number;

}