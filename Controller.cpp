/*
 * Controller.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include "Controller.h"
#include "State.h"
#include "Server.h"

#include <iostream>

const double DEFAULT(0.);

Controller::Controller() : pState_(NULL), pServer_(NULL),
    val_start_(DEFAULT), val_stop_(DEFAULT) {} // TODO garder le constructeur par défaut ?

Controller::Controller(State* pState, Server* pServer, double val_start, double val_stop) :
    pState_(pState), pServer_(pServer), val_start_(val_start), val_stop_(val_stop) {}

Controller::~Controller() {}

void Controller::refresh (double time) {
    
    double val_phen;
    double val_state;
 
  
    val_state = pState_->get_val_state();
    val_phen = pState_->get_val_phen(); 
    
    // TODO implement this function // format d'envoi des infos
    
}
