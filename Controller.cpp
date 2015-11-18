/*
 * Controller.cpp
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#include <cassert>

#include "Controller.h"

Controller::Controller() : Agent(), pState_(NULL), pServer_(NULL) {}

Controller::Controller(State* pState, Server* pServer)
    : Agent(), pState_(pState), pServer_(pServer) {}

Controller::~Controller() {}

void Controller::refresh (double) {
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

void Controller::init() {
    using namespace std;
    vector<string> legendKeys(0,"");

    if(pServer_!=NULL) {
        legendKeys.push_back("phenomenon");
        legendKeys.push_back("state");
        legendKeys.push_back("ctrl");

        pServer_->introduce(legendKeys);
    }
}
