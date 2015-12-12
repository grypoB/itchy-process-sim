#include "OnOffController.h"

namespace {
    //const double DEFAULT_VAL(.0);
    //const double DEFAULT_SWITCH(.0);
}

/** Create an actif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 * @param threshold_low minimum tolerated value by the controller
 * @param threshold_high maximum tolerated value by the controller
 * @param output_high high value taken by the controller to regulated the state
 * @param output_low low value taken by the controller to regulated the state
 *
 * @see OnOffController::refresh
 */
OnOffController::OnOffController(State* pState, Server* pServer,
                double threshold_low, double threshold_high,
                double output_high, double output_low)
               : Controller(pState, pServer),
                 threshold_low_(threshold_low), threshold_high_(threshold_high),
                 output_high_(output_high), output_low_(output_low) {}

OnOffController::~OnOffController() {}


/** Controller take the maximum value over a certain value and take the
 * minimum value under a certain value.
 */
double OnOffController::getResponse(double, double val_state, double) {
    
    if (val_state < threshold_low_) {
        return output_high_;
    }
    else if (val_state > threshold_high_) {
        return output_low_;
    }
    else { // inside acceptable margin
        return val_state;
    }
}
