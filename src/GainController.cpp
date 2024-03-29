#include "GainController.h"

/** Create an actif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 * @param val_ref value Controller wants to approach
 * @param gain factor of the reaction of Controller
 *
 * @see GainController::refresh
 */
GainController::GainController(State* pState, Server* pServer, double val_ref, double gain)
    : Controller(pState, pServer), val_ref_(val_ref), gain_(gain) {}

GainController::~GainController() {}


/** Has a proportional response
 * There are unused parameters, because it just need
 * the value of the state
 */
double GainController::getResponse(double, double val_state, double) {
    double difference;
    
    difference = val_state - val_ref_;
    return val_state - gain_ * difference;
}
