#include "SinPhenomenon.h"
#include "random.h"
#include <cmath>
#include <cfloat>
#include <cassert>



namespace {
    const double PI2(6.283185307179586);
}

/** Initialize a phenomenon wich creates a sinusoid
 * @param amplitudw amplitude of the sine wave
 * @param period period of the sine (needs to be above SinPhen::MIN_PERIOD)
 * @param offset offset to apply to the sine wave
 * @param phase phase (in radian) of the sine
 */
SinPhenomenon::SinPhenomenon(State* pState, double amplitude, double period,
                             double offset, double phase)
                            : Phenomenon(pState), period_(period),
                              offset_(offset), ampl_(amplitude), phase_(phase) {
    assert(period>=SinPhen::MIN_PERIOD);
}

SinPhenomenon::~SinPhenomenon() {}

/** Return a sinusoid
 */
double SinPhenomenon::gen_val_phen(double time) {
    return offset_ + ampl_*sin(PI2*(time + phase_)/period_);
}
