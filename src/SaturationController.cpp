#include <cassert>

#include "SaturationController.h"

namespace {
    const double DEFAULT_VAL_SAT(.0);
}

/** Default constructor, should not be called explicitly */
SaturationController::SaturationController() : Controller(), val_sat_(DEFAULT_VAL_SAT) {}

/** Create an acif controller with predefined relationship
 * @param pState the state to monitor
 * @param pServer the server to send data to
 * @param val_sat the highest value the controler can have
 *
 * It is an actif controller, as it will maybe influence the state
 * @see SaturationController::refresh
 */
SaturationController::SaturationController(State* pState, Server* pServer, double val_sat)
    : Controller(pState, pServer), val_sat_(val_sat) {}

SaturationController::~SaturationController() {}

/** Monitor the state, act if necessary and send data to server
 */
void SaturationController::refresh (double) {
    double val_state(.0);
    double val_ctrl (.0);

    val_state = get_info_state();
    
    if (val_state > val_sat_) {
        val_ctrl = val_sat_;
    }
    
    else {
        val_ctrl = val_state;
    }
    
    transmit();
    send_val_ctrl_to_server(val_ctrl);
}
