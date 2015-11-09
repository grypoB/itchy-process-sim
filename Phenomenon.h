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
	virtual ~Phenomenon();

	void update_val_phen (double time);

private:
	State* const pState;
	double val_phen_min;
	double val_phen_max;
	
protected:

    virtual double val_phen_gen(double time);
};

#endif /* PHENOMENON_H_ */
