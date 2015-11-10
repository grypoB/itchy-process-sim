/*
 * Phenomenon.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include "Phenomenon.h"
#include "State.h"
#include <iostream>

const double DEFAULT(0.);

Phenomenon::Phenomenon() :
pState_(NULL), val_phen_min_(DEFAULT), val_phen_max_(DEFAULT) {}

Phenomenon::Phenomenon(State* pState, double val_phen_min,
                       double val_phen_max) :
    pState_(pState), val_phen_min_(val_phen_min), val_phen_max_(val_phen_max) {}


Phenomenon::~Phenomenon() {}

void Phenomenon::refresh (double time) {
    
    using namespace std;
    double val_phen;
    
	val_phen = val_phen_gen(time);
	
	// TODO faire des exception pour envoyer message si valeur limites dépassées ?
	
	if (val_phen < val_phen_min_) {
	    cout<<"The phenomenon is lower than expected\n";
	    val_phen = val_phen_min_;
	}
	
	else if (val_phen > val_phen_max_) {
	    cout<<"The penomenon is higher than expected\n";
	    val_phen = val_phen_max_;
	}
	
	
	if (pState_ != NULL) {
       	pState_->set_val_phen(val_phen);
	}
}

double Phenomenon::val_phen_gen(double time) {
    return time;
}
