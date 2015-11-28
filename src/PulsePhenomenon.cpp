#include "PulsePhenomenon.h"
#include <cassert>

namespace {
    const double DEFAULT_VAL_LOW(0.);
    const double DEFAULT_VAL_HIGH(1.);
    const double DEFAULT_DELAY(0.);
    const double DEFAULT_PHASE(0.);
    const double DEFAULT_RISE(0.);
    const double DEFAULT_WIDTH(0.5);
    const double DEFAULT_FALL(0.);
    const double DEFAULT_RANDOM(0.);
    const double NO_TIME_LEFT(0.);
    const double ZERO(1e-9);
}

PulsePhenomenon::PulsePhenomenon()
                            : Phenomenon(), val_low_(DEFAULT_VAL_LOW), 
                              val_high_(DEFAULT_VAL_HIGH), t_delay_(DEFAULT_DELAY),
                              t_rise_(DEFAULT_RISE), p_high_(DEFAULT_WIDTH), 
                              t_fall_(DEFAULT_FALL), p_low_(DEFAULT_WIDTH), step_(DELAY),
                              rand_min_(DEFAULT_RANDOM), rand_max_(DEFAULT_RANDOM) {}

/** Initialize a phenomenon wich create a pulsed curve and add random values in range (min,max]
 */
PulsePhenomenon::PulsePhenomenon(State* pState, double low, double high, double delay,
                                 double rise, double p_width, double fall, double period, 
                                 double rand_min, double rand_max)
                                : Phenomenon(pState), val_low_(low), val_high_(high),
                                  t_delay_(delay), t_rise_(rise), p_high_(p_width), 
                                  t_fall_(fall), step_(DELAY), rand_min_(rand_min),
                                  rand_max_(rand_max) {
    assert(t_delay_ >= .0);
    assert(t_rise_  >= .0);
    assert(t_fall_  >= .0);
    assert(p_high_  >= .0);
    p_low_ = period - (t_rise_ + p_high_ + t_fall_);
    assert(p_low_   >= .0);
}

PulsePhenomenon::~PulsePhenomenon() {}

/** Return a pulsed function whith a random noise
 */
double PulsePhenomenon::gen_val_phen(double time) {
    double val_phen, delta_t;

    delta_t = time - previous_time_;
    do {
    switch (step_) {
        case(LOW): // if period = 0, return val_low_
            if (t_rise_ + t_fall_ + p_high_ + p_low_ <= ZERO) {
                delta_t = NO_TIME_LEFT;
                val_phen = val_low_;
                break;
            }
        case(DELAY):
            if (time_left_ < delta_t) {
                next_step (delta_t);
            }
            else {
                time_left_ -= delta_t;
                val_phen = val_low_;
                delta_t = NO_TIME_LEFT;
            }
        break;
        case(RISE):
            if (time_left_ < delta_t) {
                next_step (delta_t);
            }
            else {
                time_left_ -= delta_t;
                val_phen = val_low_ + (val_high_ - val_low_)/(t_rise_)*(t_rise_ - time_left_);
                // the previous division isn't a risk of bug if t_rise_ = 0
                delta_t = NO_TIME_LEFT;
            }
        break;
        case(HIGH):
            if (time_left_ < delta_t) {
                next_step (delta_t);
            }
            else {
                time_left_ -= delta_t;
                val_phen = val_high_;
                delta_t = NO_TIME_LEFT;
            }
        break;
        case(FALL):
            if (time_left_ < delta_t) {
                next_step (delta_t);
            }
           else {
                time_left_ -= delta_t;
                val_phen = val_high_ - (val_high_ - val_low_)/(t_fall_)*(t_fall_ - time_left_);
                // the previous division isn't a risk of bug if t_fall_ = 0
                delta_t = NO_TIME_LEFT;
            } break;
        }
    } while (delta_t > NO_TIME_LEFT);
    return val_phen;
}

void PulsePhenomenon::next_step (double& delta_t) {
    delta_t -= time_left_;

    switch (step_) {
        case(DELAY):
        case(LOW):
            step_ = RISE;
            time_left_ = t_rise_; 
        break;
        case(RISE):
            step_ = HIGH;
            time_left_ = p_high_; 
        break;
        case(HIGH):
            step_ = FALL;
            time_left_ = t_fall_; 
        break;
        case(FALL):
            step_ = LOW;
            time_left_ = p_low_; 
        break;
    }
}
