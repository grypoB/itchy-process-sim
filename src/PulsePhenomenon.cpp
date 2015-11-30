#include "PulsePhenomenon.h"
#include <cassert>

namespace {
    const double DEFAULT_VAL_LOW(0.);
    const double DEFAULT_VAL_HIGH(1.);
    const double DEFAULT_DELAY(0.);
    //const double DEFAULT_PHASE(0.);
    const double DEFAULT_RISE(0.);
    const double DEFAULT_WIDTH(0.5);
    const double DEFAULT_FALL(0.);

    const double EPSILON_ZERO(1e-9);
}

PulsePhenomenon::PulsePhenomenon()
                            : Phenomenon(), val_low_(DEFAULT_VAL_LOW), 
                              val_high_(DEFAULT_VAL_HIGH), t_delay_(DEFAULT_DELAY),
                              t_rise_(DEFAULT_RISE), p_high_(DEFAULT_WIDTH), 
                              t_fall_(DEFAULT_FALL), period_(2*DEFAULT_WIDTH) {}

/** Initialize a phenomenon wich create a pulsed response
 */
PulsePhenomenon::PulsePhenomenon(State* pState, double low, double high, double delay,
                                 double rise, double p_width, double fall, double period)
                                : Phenomenon(pState), val_low_(low), val_high_(high),
                                  t_delay_(delay), t_rise_(rise), p_high_(p_width), 
                                  t_fall_(fall), period_(period) {
    assert(t_delay_ >= .0);
    assert(t_rise_  >= .0);
    assert(t_fall_  >= .0);
    assert(p_high_  >= .0);
    assert(period_   >= t_rise_+t_fall_+p_high_);
}

PulsePhenomenon::~PulsePhenomenon() {}

/** Return a pulsed function
 */
double PulsePhenomenon::gen_val_phen(double time) {
    double val_phen(.0);

    if (time <= t_delay_ || period_<EPSILON_ZERO) {
        val_phen = val_low_;
    } else {
        time -= t_delay_;
        time -= static_cast<int>(time/period_) * period_; // fall back to a single period
        assert(time <=period_);

        if ( t_rise_>EPSILON_ZERO && time<t_rise_ ) {
            val_phen = val_low_ + (val_high_-val_low_)/(t_rise_)*(time);
        } else if (time <= (p_high_+t_rise_)) {
            val_phen = val_high_;
        } else if ( t_fall_>EPSILON_ZERO && time<(t_fall_+p_high_+t_rise_) ) {
            val_phen = val_high_ - (val_high_-val_low_)/(t_fall_)*(time-(p_high_+t_rise_));
        } else {
            val_phen = val_low_;
        }
    }

    return val_phen;
}
