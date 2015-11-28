#ifndef LOWHIGHCONTROLLER_H_
#define LOWHIGHCONTROLLER_H_

#include "Controller.h"

class LowHighController: public Controller {
    public:
        LowHighController();
        LowHighController(State* pState, Server* pServer, double switch_high, 
                                     double switch_low, double val_high, double val_low);
        virtual ~LowHighController();

    protected:
        virtual double getResponse(double, double val_state, double);
    
    private:
        double val_switch_high_; ///< value to reach so controller switch to the highest value
        double val_switch_low_; ///< value to reach so controller switch to the highest value
        double val_high_; ///< highest value controller can take
        double val_low_; ///< lowest value controller can take
};

#endif
