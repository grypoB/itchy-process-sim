/*
 * Phenomenon.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include "Phenomenon.h"
#include <cstddef>

Phenomenon::Phenomenon() : Agent(), pState_(NULL) {}

Phenomenon::Phenomenon(State* pState) : Agent(), pState_(pState) {}

Phenomenon::~Phenomenon() {}

void Phenomenon::refresh (double time) {
	if (pState_ != NULL) {
       	pState_->set_val_phen(gen_val_phen(time));
	}
}
