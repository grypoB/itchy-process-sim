#include "RngPhenomenon.h"
#include "random.h"

/** Initialize a phenomenon wich outputs random values in range (min,max]
 */
RngPhenomenon::RngPhenomenon(State* pState, double min, double max) 
    : Phenomenon(pState), min_(min), max_(max)  {}

RngPhenomenon::~RngPhenomenon() {}

/** Return a random number in range (min_,max_]
 */
double RngPhenomenon::gen_val_phen(double) {
    return Rand::rand(min_, max_);
}
