#include "State.h"
#include <cassert>

namespace {
    const double I_MAX(1.); // influence factor max/min
    const double I_MIN(0.);
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
            : Agent(), i_phen_(i_phen),  i_ctrl_(i_ctrl), val_phen_(DEFAULT),
              val_ctrl_(DEFAULT), val_state_(init_state_val),
              prevTime_(DEFAULT) {
        
    assert(i_phen>=I_MIN);
    assert(i_phen<=I_MAX);
    
    assert(i_ctrl>=I_MIN);
    assert(i_ctrl<=I_MAX);
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
