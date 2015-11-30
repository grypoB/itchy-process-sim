#include "OnOffController.h"

namespace {
    const double DEFAULT_VAL(.0);
    const double DEFAULT_SWITCH(.0);
}

/** Default constructor, should not be called explicitly */
OnOffController::OnOffController() : Controller(), val_switch_high_(DEFAULT_SWITCH),
                                         val_switch_low_(DEFAULT_SWITCH),
                                         val_high_(DEFAULT_VAL), val_low_(DEFAULT_VAL) {}

/** Create an actif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 * @param val_sat the highest value the controler can have
 *
 * It is an actif controller, as it will maybe influence the state
 * @see OnOffController::refresh
 */
OnOffController::OnOffController(State* pState, Server* pServer, double switch_high, 
                                     double switch_low, double val_high, double val_low)
                                     : Controller(pState, pServer), val_switch_high_(switch_high), val_switch_low_(switch_low),
                                       val_high_(val_high), val_low_(val_low)  {}

OnOffController::~OnOffController() {}


/** Controller take the maximum value over a certain value and take the
 * minimum value under a certain value.
 */
double OnOffController::getResponse(double, double val_state, double) {
    
    if (val_state < val_switch_low_) {
        return val_low_;
    }
    else if (val_state > val_switch_high_) {
        return val_high_;
    }
    else {
        return val_state;
    }
}
