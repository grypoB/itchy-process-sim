#include "GainController.h"

namespace {
    const double DEFAULT_VAL_REF(.0);
    const double DEFAULT_GAIN(1.);
}

/** Default constructor, should not be called explicitly */
GainController::GainController() : Controller(), val_ref_(DEFAULT_VAL_REF), gain_(DEFAULT_GAIN) {}

/** Create an acif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 * @param val_ref value Controller wants to approach
 * @param gain factor of the reaction of Controller
 *
 * It is an actif controller, as it will maybe influence the state
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
