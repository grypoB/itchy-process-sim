#include <cassert>

#include "Controller.h"

namespace {
    enum Agent {PHENOMENON = 0, STATE, CTRL};
    const unsigned int NB_AGENT = 3;
}

/** Default constructor, should not be called explicitly */
Controller::Controller() : Agent(), pState_(0), pServer_(0),
                           legend_keys_(NB_AGENT, "") {}

/** Create a passif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 *
 * It is a passif controller, as it won't influence the state
 * @see Controller::refresh
 */
Controller::Controller(State* pState, Server* pServer)
    : Agent(), pState_(pState), pServer_(pServer),
      legend_keys_(NB_AGENT, "") {}

Controller::~Controller() {}

/** Monitor the state
 */
void Controller::refresh (double time) {
    double val_state(.0);
    double val_phen(.0);

    if (pState_!=NULL && pServer_!=NULL) { 
        
        val_phen  = pState_->get_val_phen() ;
        val_state = pState_->get_val_state();
        val_ctrl = getResponse(time, val_state, val_phen);
        // react to state and phen value
        pState->set_val_ctrl(val_ctrl);

        // log to the server
        pServer_->send(legend_keys_[PHENOMENON], val_phen);
        pServer_->send(legend_keys_[STATE], val_state);
        pServer_->send(legend_keys_[CTRL], val_ctrl);
    }

    
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


/** Associate a name with values, when sent to server
 *  
 *  All legend_keys (aka name) should be different
 *  A "" is equivalent to the value nt being sent to server
 *  @param legendState name to give to the state 
 *  @param legendPhen name to give to the phenomenon 
 *  @param legendCtrl name to give to the controller
 *
 *  An exemple usage would be :
 *  set_legend_keys("room temparature", "outside temparature", "heater")
 */
void Controller::set_legend_keys(std::string legendState,
                                 std::string legendPhen,
                                 std::string legendCtrl) {
        legend_keys_.at(PHENOMENON) = legendPhen;
        legend_keys_.at(STATE) = legendState;
        legend_keys_.at(CTRL) = legendCtrl;
}

double Controller::getResponse(double, double valState, double) {
    return valState;
}

