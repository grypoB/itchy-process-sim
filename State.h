/*
 * State.h
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#ifndef STATE_H_
#define STATE_H


class State {
public:
	State();
	virtual ~State();

	void update_state ();

private:

	const double i_phen_;
	const double i_ctrl_;
	
	double val_phen_;
	double val_ctrl_;
	double eff_state_;
}

#endif /* STATE_H_ */
