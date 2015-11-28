#include <cstddef>
#include "Phenomenon.h"
#include "random.h"

namespace {
    const double DEFAULT_SIGMA(.0); // standard deviation
}

/** Default constructor, should not be called explicitly */
Phenomenon::Phenomenon() : Agent(), pState_(NULL), 
                           standard_deviation_(DEFAULT_SIGMA) {}

/**
 * @param pState state to influence
 */
Phenomenon::Phenomenon(State* pState) : Agent(), pState_(pState),
                                        standard_deviation_(DEFAULT_SIGMA) {}

Phenomenon::~Phenomenon() {}

void Phenomenon::refresh (double time) {
	if (pState_ != NULL) {
       	pState_->set_val_phen(Rand::normal_dist(gen_val_phen(time),
                                                standard_deviation_));
	}
}

void Phenomenon::set_standard_deviation(double sigma) {
    standard_deviation_ = sigma;
}
