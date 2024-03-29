#include <cassert>
#include <iostream>
#include <string>
#include "State.h"
#include "NumericLimit.h"

namespace {
    const double DEFAULT(0.); // default val
}

// --------------------------------------------------------------------------
// Constructors / Destructors

/** Construct a ready to use state
 *  @param i_phen, i_ctrl influence factor of respectively phenomenon and
 *         controller that might affect it
 *  @param init_state_val initial value of the state (at t=0)
 */
State::State(double i_phen, double i_ctrl, double init_state_val)
            : Agent(), i_phen_(i_phen),  i_ctrl_(i_ctrl),
              val_state_min_(NumericLimit::DOUBLE_MIN), 
              val_state_max_(NumericLimit::DOUBLE_MAX),
              val_phen_(DEFAULT), val_ctrl_(DEFAULT),
              val_state_(init_state_val), prevTime_(DEFAULT) {

    if (i_phen < 0) {
        throw std::string("The phenomenon's influence is negative");
    }
    else if (i_ctrl < 0) {
        throw std::string("The controller's influence is negative");
    }
    // influence factor above 1 are allowed, as they provide good result
    // for short simulation deltaT
}

State::~State() {}


// --------------------------------------------------------------------------
// Redefenition of Agent
/** Update state according to val setted by controller/phenomenon
 * @see State::set_val_phen
 * @see State::set_val_ctrl
 */
void State::refresh (double time) {
    double dt(time-prevTime_);

    val_state_ += i_phen_*dt * (val_phen_-val_state_)
                + i_ctrl_*dt * (val_ctrl_-val_state_);

    if ((i_phen_+i_ctrl_)*dt > 2) { // not stable simulation ('2' comes from noerical analysis)
        std::cout << "[WARNING] [WARNING] State value isn't stable and might diverge" << std::endl;
    } else if ((i_phen_+i_ctrl_)*dt > 1) { // influence could be over "100%"
        std::cout << "[WARNING] Some values of state might not have any physical meaning" << std::endl;
    }

    if (val_state_ < val_state_min_) {
        val_state_ = val_state_min_;
    }
    else if (val_state_ > val_state_max_) {
        val_state_ = val_state_max_;
    }

    prevTime_ = time;
}

void State::init() {
    prevTime_ = .0;
    // TODO add val_state_ = starting_val
}


// --------------------------------------------------------------------------
// Setters
void State::set_val_phen (double val_phen) {
    val_phen_ = val_phen;
}

void State::set_val_ctrl (double val_ctrl) {
    val_ctrl_ = val_ctrl;
}


/** Set the boundaries of the interval wherein the state value must be
 * @param val_state_min, val_state_max respectively the lower and the upper
 *        limit of the interval
 *
 * If not called, they take the minimum/maximum value possible for the
 * type double
 */
void State::set_boundaries(double val_state_min, double val_state_max) {
  val_state_min_ = val_state_min;
  val_state_max_ = val_state_max;
}

// --------------------------------------------------------------------------
// Getters
double State::get_val_phen() const {
    return val_phen_;
}

double State::get_val_state() const {
    return val_state_;
}

double State::get_val_ctrl() const {
    return val_ctrl_;
}
