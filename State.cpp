/*
 * State.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include "State.h"
#include "Phenomenon.h"

namespace state {

State::State() {
	// TODO Auto-generated constructor stub

}

State::~State() {
	// TODO Auto-generated destructor stub
}

double get_val_phen () const {
	return val_phen_;
}

double get_eff_state () const {
	return eff_state_;
}

void update_state () const {
	val_phen_ = get_val_phen ();
}

void set_update_ctrl_state (double val_ctrl) {
	eff_state_ = eff_state_ + (val_phen_ - eff_state_) * i_phen_ 
				 + (val_ctrl - eff_state_) * i_ctrl_;

 // TOOD : this function seems to be UAF (ugly as f***) -> find an other way ?
} 

} /* namespace state */
