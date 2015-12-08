#include <cassert>
#include "NumericLimit.h"
#include "Controller.h"

namespace {
    enum Agent {PHENOMENON = 0, STATE, CTRL};
    const unsigned int NB_AGENT = 3;
}

/** Create a passif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 *
 * It is a passif controller, as it won't influence the state
 * @see Controller::refresh
 */
Controller::Controller(State* pState, Server* pServer)
    : Agent(), val_ctrl_min_(NumericLimit::DOUBLE_MIN), 
      val_ctrl_max_(NumericLimit::DOUBLE_MAX), 
      pState_(pState), pServer_(pServer), 
      legend_keys_(NB_AGENT, ""), refreshRate_(0) {}

Controller::~Controller() {}

/** Monitor the state
 */
void Controller::refresh (double time) {
    double val_state(.0);
    double val_phen(.0);
    double val_ctrl(.0);

    if (pState_!=NULL && pServer_!=NULL) {

        val_phen  = pState_->get_val_phen() ;
        val_state = pState_->get_val_state();

            //val_ctrl = getResponse(time, val_state, val_phen);
        // react to state and phen value
        if (time - lastTime_ >= refreshRate_) { // update ctrl value
            lastTime_ = time;
            val_ctrl = getResponse(time, val_state, val_phen);
            lastOutput_ = val_ctrl;
        } else { // take last outpurted value
            val_ctrl = lastOutput_;
        }

        if (val_ctrl < val_ctrl_min_) {
            val_ctrl = val_ctrl_min_;
        }
        else if (val_ctrl > val_ctrl_max_) {
            val_ctrl = val_ctrl_max_;
        }

        pState_->set_val_ctrl(val_ctrl);

        // log to the server
        pServer_->send(legend_keys_[PHENOMENON], val_phen);
        pServer_->send(legend_keys_[STATE], val_state);
        pServer_->send(legend_keys_[CTRL], val_ctrl);
    }


}


/** Initialize controller/server communication
 */
void Controller::init() {
    if(pServer_!= 0) {
        pServer_->introduce(legend_keys_);
        lastTime_ = NumericLimit::DOUBLE_MIN;
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

void Controller::set_boundaries(double val_ctrl_min, double val_ctrl_max) {
    val_ctrl_min_ = val_ctrl_min;
    val_ctrl_max_ = val_ctrl_max;
}

void Controller::set_refresh_rate(double deltaT) {
    refreshRate_ = deltaT;
}

/** Follow the value of the state
 * There are unused parameters, because it just need the value of the state
 */
double Controller::getResponse(double, double val_state, double) {
    return val_state;
}
