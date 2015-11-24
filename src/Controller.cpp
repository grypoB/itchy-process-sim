#include <cassert>

#include "Controller.h"

namespace {
    enum Agent {PHENOMENON = 0, STATE, CTRL};
    const unsigned int NB_AGENT = 3;
}

/** Default constructor, should not be called explicitly */
Controller::Controller() : Agent(), pState_(0), pServer_(0) {}

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

/** Monitor the state
 */
void Controller::refresh (double) {
    double val_state;
    
    val_state = get_info_state();
    pState_->set_val_ctrl(val_state); // so ctrl has no effect
    
    transmit();
}


/** Initialize controller/server communication
 * If not called before refresh, server won't know what to print
 */
void Controller::init() {
    using namespace std;
    

    if(pServer_!= 0) {
        if(legend_keys_.size() == 0) {
            legend_keys_.push_back("phenomenon");
            legend_keys_.push_back("state");
            legend_keys_.push_back("controller");
        }
        
        pServer_->introduce(legend_keys_);
    }
}


/** Initialize name of the agents of the simulation
 * If not called before init or with incorrect number of arguments (3),
 * default name will be given
 *
 * @param legend Vector containing the legend key which will be outputed.
 *               The order they are in the vector is the following order:
 *               phenomenon, state, controller
 */
void Controller::set_legend(std::vector<std::string> legend) {
    using namespace std;
    
    if(legend_keys_.size() != NB_AGENT) {
        legend_keys_.push_back("phenomenon");
        legend_keys_.push_back("state");
        legend_keys_.push_back("controller");
    }
            
    else {
        legend_keys_.push_back(legend[PHENOMENON]);
        legend_keys_.push_back(legend[STATE]);
        legend_keys_.push_back(legend[CTRL]);
    }
}

/** Return the current value of the state
 */
double Controller::get_info_state() {
    
    assert(pState_!=0);
    return pState_->get_val_state();
}

/** Send to Server the values that won't be changed
 */
void Controller::transmit() {
    double val_phen (.0);
    double val_state(.0);
    
    assert(pState_!=0 && pServer_!=0);

    val_phen  = pState_->get_val_phen() ;
    val_state = pState_->get_val_state();
    
    pServer_->send(legend_keys_[PHENOMENON], val_phen );
    pServer_->send(legend_keys_[STATE], val_state);
}

/** Send the value of the controller to Server
 */
void Controller::send_val_ctrl_to_server(double val_ctrl) {
    assert(pServer_!=0);
    
    pServer_->send(legend_keys_[CTRL], val_ctrl);
}
