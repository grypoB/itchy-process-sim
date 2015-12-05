#include "PulsePhenomenon.h"
#include <string>
#include <cassert>

namespace {
    const double EPSILON_ZERO(1e-9); // for double comparisons
    const double POSITIVE_TIME(.0);
}

/** Initialize a phenomenon wich create a pulsed response
 * @param low low value of the pulse
 * @param high high value of the pulse
 * @param p_width time the pulse stays high
 * @param period period ot the entire pulse
 * @param rise time the pulse takes to go from low to high
 * @param fall time the pulse takes to go from high to low
 * @param delay initial delay of the pulse, it will stay at 'low'
 *              during this time
 */
PulsePhenomenon::PulsePhenomenon(State* pState, double low, double high,
                                 double p_width, double period,
                                 double rise, double fall,
                                 double delay)
                                : Phenomenon(pState), val_low_(low), val_high_(high),
                                  t_delay_(delay), t_rise_(rise), p_high_(p_width), 
                                  t_fall_(fall), period_(period) {
    if (t_delay_ < POSITIVE_TIME) {
        throw std::string ("The delay of the pulsed phenomenon is negative");
    }
    if (t_rise_ < POSITIVE_TIME) {
        throw std::string ("The time of rise of the pulsed phenomenon is negative");
    }
    if (t_fall_ < POSITIVE_TIME) {
        throw std::string ("The time of fall of the pulsed phenomenon is negative");
    }
    if (p_high_ < POSITIVE_TIME) {
        throw std::string ("The period of the high value of the pulsed phenomenon "
                           "is negative");
    }
    if (period_ < t_rise_+t_fall_+p_high_) {
        throw std::string ("The total period of the pulsed phenomenon is lower than"
                           " the sum of other period");
    }
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
        assert(time <=period_); // small debug check

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
