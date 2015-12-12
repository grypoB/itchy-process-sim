#include "SaturationController.h"

/** Create an actif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 * @param val_sat val to output if state above this value
 *
 * Act as a dumb cooler
 *
 * @see SaturationController::refresh
 */
SaturationController::SaturationController(State* pState, Server* pServer, double val_sat)
    : Controller(pState, pServer), val_sat_(val_sat) {}

SaturationController::~SaturationController() {}


/** Turn on when val_state is over a certain value
 * There are unused parameters, because it just need
 * the value of the state
 */
double SaturationController::getResponse(double, double val_state, double) {
    
    if (val_state > val_sat_) {
        return val_sat_;
    }
    else {
        return val_state;
    }
}
