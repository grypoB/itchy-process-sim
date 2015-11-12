/*
 * State.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include "State.h"
#include <cassert>

const double I_MAX(1.);
const double I_MIN(0.);
const double DEFAULT(0.);

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

void State::refresh (double time) {
    eff_state_ += i_phen_ * (val_phen_-eff_state_)
                + i_ctrl_ * (val_ctrl_-eff_state_);
}

void State::set_val_phen (double val_phen) {
    val_phen_ = val_phen;
}

double State::get_val_phen() const {
    return val_phen_;
}

double State::get_val_state() const {
    return eff_state_;
}

