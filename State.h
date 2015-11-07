/*
 * State.h
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#ifndef STATE_H_
#define STATE_H_

#include "Phenomenon.h"

namespace state {

class State {
public:
	State();
	virtual ~State();

	double get_val_phen() const;
	double get_eff_state() const;

	void set_ctrl_update_state(val_ctrl);

private:
// TODO : should i_phen_ & i_ctrl be constant ?
	double i_phen_;
	double i_ctrl_;
	
	double val_phen_;
	double eff_state_;

	Phenomenon * incident_phen_;

};

} /* namespace state */

#endif /* STATE_H_ */
