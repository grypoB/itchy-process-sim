/*
 * Phenomenon.h
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#ifndef PHENOMENON_H_
#define PHENOMENON_H_

#include "State.h"

class Phenomenon {
public:

	Phenomenon();
	Phenomenon(State* pState, double val_phen_min, double val_phen_max);
	virtual ~Phenomenon();

	void refresh (double time);

private:

	State* const pState_;
	const double val_phen_min_;
	const double val_phen_max_;
	
protected:

    virtual double val_phen_gen(double time);
};

#endif /* PHENOMENON_H_ */
