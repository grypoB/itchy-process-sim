#include <ctime>
#include <cstdlib>

#include "random.h"

namespace {
/**
 * @return random number in range (0,1]
 * More precisely [4.656612877414201268067017736029811203479766845703125e-10 , 1]
 */
double randDouble() {
    static bool initialized(false);

    if (!initialized) {
        srand(time(NULL)); // initialized list of random number
        initialized = true;
    }

    // rand return int in [1, RAND_MAX-1]
    return static_cast<double>(std::rand())/(RAND_MAX-1);
}
} /* anonymous namespace */

namespace Rand {

/** Return random number in (min,max]
 *  @param min,max if min>max, return random number in [max,min)
 */
double rand(double min, double max) {
    /*
    if (min>max) {
        double temp(min);
        min = max;
        max = temp;
    }
    */

    return min + randDouble()*(max-min);
}

} /* namespsace Rand */
