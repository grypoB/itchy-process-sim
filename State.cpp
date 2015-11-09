/*
 * State.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include "State.h"

State::State() {
	// TODO Auto-generated constructor stub

}

State::~State() {
	// TODO Auto-generated
	destructor stub
}

void update_state () {
    eff_state_ += i_phen_ * (val_phen_-eff_state_)
                + i_ctrl_ * (val_ctrl_-eff_state_);
}

