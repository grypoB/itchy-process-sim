#include <ctime>
#include <cstdlib>
#include <cmath>

#include "random.h"

namespace {
    const double PI(3.14159265358979323846); // pi
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

    /** Return a number which would fall into the given normal distribution
     *  It uses the Box-Muller transform
     *  @param mean mean of the normal distribution
     *  @param sigma standard deviation of the normal distribution
     */
    double normal_dist(double mean, double sigma) {
        double y(sqrt(-2*log(randDouble()))*cos(2*PI*randDouble()));
        return mean + sigma*y;
    }
} /* namespsace Rand */
