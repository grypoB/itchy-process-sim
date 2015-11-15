/*
 * State.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include "State.h"
#include <cassert>

// TODO put in namespace ? check with teacher
const double I_MAX(1.); // influence factor max/min
const double I_MIN(0.);
const double DEFAULT(0.);

// --------------------------------------------------------------------------
// Constructors / Destructors
State::State() :  i_phen_(I_MAX), i_ctrl_(I_MAX), val_phen_(DEFAULT),
                  val_ctrl_(DEFAULT), eff_state_(DEFAULT) {}

State::State(double i_phen, double i_ctrl, double eff_state) :
    i_phen_(i_phen),  i_ctrl_(i_ctrl), val_phen_(DEFAULT), val_ctrl_(DEFAULT), eff_state_(eff_state) {
        
    assert(i_phen>=I_MIN);
    assert(i_phen<=I_MAX);
    
    assert(i_ctrl>=I_MIN);
    assert(i_ctrl<=I_MAX);
}

State::~State() {}


// --------------------------------------------------------------------------
// Redefenition of Agent
void State::refresh (double time) {
    static double prevTime(.0); // TODO shared between all state instances ==> problem
    double dtime(time-prevTime);

    eff_state_ += i_phen_*dtime * (val_phen_-eff_state_)
                + i_ctrl_*dtime * (val_ctrl_-eff_state_);

    prevTime = time;
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
    return eff_state_;
}

double State::get_val_ctrl() const {
    return val_ctrl_;
}
