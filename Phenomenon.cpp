#include "Phenomenon.h"
#include <cstddef>

/** Default constructor, should not be called explicitly */
Phenomenon::Phenomenon() : Agent(), pState_(NULL) {}

/**
 * @param pState state to influence
 */
Phenomenon::Phenomenon(State* pState) : Agent(), pState_(pState) {}

Phenomenon::~Phenomenon() {}

void Phenomenon::refresh (double time) {
	if (pState_ != NULL) {
       	pState_->set_val_phen(gen_val_phen(time));
	}
}
