#include <cstddef>
#include "NumericLimit.h"
#include "Phenomenon.h"
#include "random.h"

/**
 * @param pState state to influence
 */
Phenomenon::Phenomenon(State* pState) : Agent(), pState_(pState),
                                        standard_deviation_(Phen::DEFAULT_SIGMA),
                                        val_phen_min_(NumericLimit::DOUBLE_MIN),
                                        val_phen_max_(NumericLimit::DOUBLE_MAX) {}

Phenomenon::~Phenomenon() {}


void Phenomenon::refresh (double time) {
	double val_phen;
	if (pState_ != NULL) {
       	val_phen = Rand::normal_dist(gen_val_phen(time), standard_deviation_);

        if (val_phen < val_phen_min_) {
        	pState_->set_val_phen(val_phen_min_);
        }
        else if (val_phen > val_phen_max_) {
         	pState_->set_val_phen(val_phen_max_);
        }
        else {
        	pState_->set_val_phen(val_phen);
        }
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


/** Set the boundaries of the interval wherein the phenomenon value must be
 * @param val_phen_min, val_phen_max respectively the lower and the upper
 *        limit of the interval
 *
 * If not called, they take the minimum/maximum value possible for the
 * type double
 */
void Phenomenon::set_boundaries(double val_phen_min, double val_phen_max) {
    val_phen_min_ = val_phen_min;
    val_phen_max_ = val_phen_max;
}
