#include "SinPhenomenon.h"
#include "random.h"
#include <cmath>
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
}

SinPhenomenon::SinPhenomenon()
                            : Phenomenon(), period_(DEFAULT_PERIOD),
                              offset_(DEFAULT_OFFSET), ampl_(DEFAULT_AMPLITUDE),
                              phase_(DEFAULT_PHASE) {}

/** Initialize a phenomenon wich create a sinusoid
 */
SinPhenomenon::SinPhenomenon(State* pState, double period,
                             double offset, double ampl, double phase) 
                            : Phenomenon(pState), period_(period),
                              offset_(offset), ampl_(ampl), phase_(phase) {}

SinPhenomenon::~SinPhenomenon() {}

/** Return a sinusoid
 */
double SinPhenomenon::gen_val_phen(double time) {
    return offset_ + ampl_*sin(PI2*(time + phase_)/period_);
}
