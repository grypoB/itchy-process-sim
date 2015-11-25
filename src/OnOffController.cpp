#include "OnOffController.h"

namespace {
    const double DEFAULT_VAL_SAT(.0);
}

/** Default constructor, should not be called explicitly */
OnOffController::OnOffController() : Controller(), val_sat_(DEFAULT_VAL_SAT) {}

/** Create an acif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 * @param val_sat the highest value the controler can have
 *
 * It is an actif controller, as it will maybe influence the state
 * @see OnOffController::refresh
 */
OnOffController::OnOffController(State* pState, Server* pServer, double val_sat)
    : Controller(pState, pServer), val_sat_(val_sat) {}

OnOffController::~OnOffController() {}


/** Turn on when val_state is over a certain value
 * There are unused parameters, because it just need
 * the value of the state
 */
double OnOffController::getResponse(double, double val_state, double) {
    
    if (val_state > val_sat_) {
        return val_sat_;
    }
    else {
        return val_state;
    }
}
