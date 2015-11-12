/*
 * Controller.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include <cassert>

#include "Controller.h"

Controller::Controller() : pState_(NULL), pServer_(NULL) {}

Controller::Controller(State* pState, Server* pServer)
    : pState_(pState), pServer_(pServer) {}

Controller::~Controller() {}

void Controller::refresh (double time) {
    double val_phen (.0);
    double val_ctrl (.0);
    double val_state(.0);
  
    assert(pState_!=NULL && pServer_!=NULL);

    val_phen  = pState_->get_val_phen() ;
    val_ctrl  = pState_->get_val_ctrl() ;
    val_state = pState_->get_val_state();
    
    pState_->set_val_ctrl(val_state); // so ctrl has no effect
    
    // TODO check server format output
    pServer_->send("phenomenon", val_phen );
    pServer_->send("state",      val_state);
    pServer_->send("ctrl",       val_ctrl );
}
