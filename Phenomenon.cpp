/*
 * Phenomenon.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include "Phenomenon.h"
#include "State.h"

Phenomenon() {
	// TODO Auto-generated constructor stub

}

~Phenomenon() {
	// TODO Auto-generated destructor stub
}

void update_val_phen (double time) {
    
    double val_phen;
	// TODO mettre assert sur valeur
	val_phen = val_phen_gen(time);
	
	pState->set_val_phen(val_phen);
}

double val_phen_gen(double time) {
    
    return time;
}