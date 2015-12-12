#include <cmath>
#include <string>
#include "SinPhenomenon.h"
#include "random.h"



namespace {
    const double PI2(6.283185307179586);
}

/** Initialize a phenomenon wich creates a sinusoid
 * @param pState state to influence
 * @param amplitude amplitude of the sine wave
 * @param period period of the sine (needs to be above SinPhen::MIN_PERIOD)
 * @param offset offset to apply to the sine wave
 * @param phase delay in deltaT of the sinusoid
 */
SinPhenomenon::SinPhenomenon(State* pState, double amplitude, double period,
                             double offset, double phase)
                            : Phenomenon(pState), period_(period),
                              offset_(offset), ampl_(amplitude), phase_(phase) {
                              	
    if (period < SinPhen::MIN_PERIOD) {
    	throw std::string ("The period of the sinusoid is too low");
    }
}

SinPhenomenon::~SinPhenomenon() {}

/** Return a sinusoid
 */
double SinPhenomenon::gen_val_phen(double time) {
    return offset_ + ampl_*sin(PI2*(time + phase_)/period_);
}
