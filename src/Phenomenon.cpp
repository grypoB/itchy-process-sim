#include <cstddef>
#include "Phenomenon.h"
#include "random.h"

/**
 * @param pState state to influence
 */
Phenomenon::Phenomenon(State* pState) : Agent(), pState_(pState),
                                        standard_deviation_(Phen::DEFAULT_SIGMA) {}

Phenomenon::~Phenomenon() {}

void Phenomenon::refresh (double time) {
	if (pState_ != NULL) {
       	pState_->set_val_phen(Rand::normal_dist(gen_val_phen(time),
                                                standard_deviation_));
	}
}


/** Set random variation on phenomenon output based on a normal distribution
 * @param sigma standard deviation of the variation to apply
 *
 * If not called, sigma is 0, hence no noise is added.
 * Otherwise the output for a given time is normaly distributed arround
 * the classic output (with the given standard deviation)
 */
void Phenomenon::set_standard_deviation(double sigma) {
    standard_deviation_ = sigma;
}
