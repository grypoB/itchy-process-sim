#ifndef ONOFFCONTROLLER_H_
#define ONOFFCONTROLLER_H_

#include "Controller.h"

class OnOffController: protected Controller {
    public:
        OnOffController();
        OnOffController(State* pState, Server* pServer, double val_sat);
        virtual ~OnOffController();

    protected:
        double getResponse(double, double val_state, double);
    
    private:
        double val_sat_;
};

#endif
