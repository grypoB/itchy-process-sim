#ifndef RANDOM_H_
#define RANDOM_H_

namespace Rand{
    double rand(double min=0, double max=1); // return random number in (min,max]
    double normal_dist(double mean, double sigma); // normal distribution
}

#endif
