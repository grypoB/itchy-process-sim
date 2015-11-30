#ifndef SATURATIONCONTROLLER_H_
#define SATURATIONCONTROLLER_H_

#include "Controller.h"

class SaturationController: public Controller {
    public:
        SaturationController();
        SaturationController(State* pState, Server* pServer, double val_sat);
        virtual ~SaturationController();

    protected:
        virtual double getResponse(double, double val_state, double);
    
    private:
        double val_sat_; ///< value max before controller turns on
};

#endif
