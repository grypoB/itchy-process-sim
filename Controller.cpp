#include <cassert>

#include "Controller.h"

/** Default constructor, should not be called explicitly */
Controller::Controller() : Agent(), pState_(NULL), pServer_(NULL) {}

/** Create a passif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 *
 * It is a passif controller, as it won't influence the state
 * @see Controller::refresh
 */
Controller::Controller(State* pState, Server* pServer)
    : Agent(), pState_(pState), pServer_(pServer) {}

Controller::~Controller() {}

/** Monitor the state and send data to server
 */
void Controller::refresh (double) {
    double val_phen (.0);
    double val_state(.0);
  
    assert(pState_!=NULL && pServer_!=NULL);

    val_phen  = pState_->get_val_phen() ;
    val_state = pState_->get_val_state();
    
    pState_->set_val_ctrl(val_state); // so ctrl has no effect
    
    // TODO check server format output
    pServer_->send("phenomenon", val_phen );
    pServer_->send("state",      val_state);
}


/** Initialize controller/server communication
 * If not called before refresh, server won't know what to print
 */
void Controller::init() {
    using namespace std;
    vector<string> legendKeys(0,"");

    if(pServer_!=NULL) {
        legendKeys.push_back("phenomenon");
        legendKeys.push_back("state");

        pServer_->introduce(legendKeys);
    }
}
