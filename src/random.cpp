#include <ctime>
#include <cstdlib>

#include "random.h"

namespace {
    /**
     * @return random number in range (0,1]
     * More precisely [~4.656612877e-10, 1]
     */
    double randDouble() {
        static bool initialized(false);

        if (!initialized) {
            // initialized list of random number
            std::srand(static_cast<unsigned int>(std::time(NULL)));
            (void) std::rand(); // call it a first time to help scramble
                                // the first random value of two
                                // program execution in sucession
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
        return min + randDouble()*(max-min);
    }
} /* namespsace Rand */
