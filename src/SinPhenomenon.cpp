#include "SinPhenomenon.h"
#include "random.h"
#include <cmath>
#include <cfloat>
#include <cassert>



namespace {
    const double DEFAULT_MIN(0.);
    const double DEFAULT_MAX(100.);
    const double PI2(6.283185307179586);
    const double DEFAULT_OFFSET(0.);
    const double DEFAULT_PHASE(0.);
    const double DEFAULT_PERIOD(1.);
    const double DEFAULT_AMPLITUDE(0.);
    const double SAT_MAX(DBL_MAX);
    const double SAT_MIN(-DBL_MAX);
}

SinPhenomenon::SinPhenomenon()
                            : Phenomenon(), period_(DEFAULT_PERIOD),
                              offset_(DEFAULT_OFFSET), ampl_(DEFAULT_AMPLITUDE),
                              phase_(DEFAULT_PHASE), sat_min_(SAT_MIN), 
                              sat_max_(SAT_MAX) {}

/** Initialize a phenomenon wich create a sinusoid
 */
SinPhenomenon::SinPhenomenon(State* pState, double period, double offset, 
                             double ampl, double phase, double sat_min, 
                             double sat_max) 
                            : Phenomenon(pState), period_(period),
                              offset_(offset), ampl_(ampl), phase_(phase), 
                              sat_min_(sat_min), sat_max_(sat_max) {
    assert(period_ > 0.);
    assert(sat_min_ <= sat_max_);
}

SinPhenomenon::~SinPhenomenon() {}

/** Return a sinusoid
 */
double SinPhenomenon::gen_val_phen(double time) {
    double val_phen(offset_ + ampl_*sin(PI2*(time + phase_)/period_));

    if(val_phen < sat_min_) {
        return sat_min_;
    }
    else if(val_phen > sat_max_) {
        return sat_max_;
    }
    else {
        return val_phen;
    }
}
