/*
 * Controller.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include "Controller.h"
#include "State.h"
#include "Server.h"

// TODO check wether this constant must be in a namespace

Controller::Controller() : pState_(NULL), pServer_(NULL) {} // TODO garder le constructeur par défaut ?

Controller::Controller(State* pState, Server* pServer)
    : pState_(pState), pServer_(pServer) {}

Controller::~Controller() {}

void Controller::refresh (double time) {
    double val_phen;
    double val_state;
  
    val_state = pState_->get_val_state();
    val_phen  = pState_->get_val_phen(); 
    
    // TODO implement this function // format d'envoi des infos
    
    // stub
    pServer_->send("phenomenon", val_phen);
    pServer_->send("state", val_state);
}
