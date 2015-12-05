#ifndef GAINCONTROLLER_H_
#define GAINCONTROLLER_H_

#include "Controller.h"

class GainController: public Controller {
    public:
        GainController(State* pState, Server* pServer, double val_ref, double gain);
        virtual ~GainController();

    protected:
        double getResponse(double, double val_state, double);
    
    private:
        double val_ref_; ///< value Controller wants to approach
        double gain_; ///< factor of the reaction of Controller
};

#endif
