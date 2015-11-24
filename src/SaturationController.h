#ifndef SATURATIONCONTROLLER_H_
#define SATURATIONCONTROLLER_H_

#include "Controller.h"

class SaturationController: protected Controller {
    public:
        SaturationController();
        SaturationController(State* pState, Server* pServer, double val_sat);
        virtual ~SaturationController();

        virtual void refresh(double time);

    private:
        double val_sat_;
};

#endif
