#include "SinPhenomenon.h"
#include "random.h"
#include <cmath>
#include <cassert>
#include <cfloat>



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
    const double START_TIME(0.);
}

SinPhenomenon::SinPhenomenon()
                            : Phenomenon(), min_(DEFAULT_MIN), max_(DEFAULT_MAX),
                              previous_time_(START_TIME), periode_(DEFAULT_PERIOD),
                              offset_(DEFAULT_OFFSET), ampl_(DEFAULT_AMPLITUDE),
                              phase_(DEFAULT_PHASE), sat_min_(SAT_MIN),
                              sat_max_(SAT_MAX) {}

/** Initialize a phenomenon wich takes random values in range (min,max]
 */
SinPhenomenon::SinPhenomenon(State* pState, double min, double max) // TODO How to deal with optional values ?
    : Phenomenon(pState), min_(min), max_(max)  {
        assert(periode_ <= .0);
    }

SinPhenomenon::~SinPhenomenon() {}

/** Return a sinusoid whith a random noise
 */
double SinPhenomenon::gen_val_phen(double time) {
    double val_phen;

    time += previous_time_;

    val_phen = offset_ + ampl_*sin(PI2*(time + phase_)/periode_);
    val_phen += Rand::rand(min_, max_);

    previous_time_ = time;

    return val_phen;
}
