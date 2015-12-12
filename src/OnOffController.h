/** @file
 *  @author Guillaume Duc **/

#ifndef ONOFFCONTROLLER_H_
#define ONOFFCONTROLLER_H_

#include "Controller.h"

class OnOffController: public Controller {
    public:
        OnOffController(State* pState, Server* pServer,
                        double threshold_low, double threshold_high,
                        double output_high, double output_low);
        virtual ~OnOffController();

    protected:
        virtual double getResponse(double, double val_state, double);
    
    private:
        double threshold_low_;  ///< Min acceptable value of the state
        double threshold_high_; ///< Max acceptable value of the state
        double output_high_; ///< highest value controller can output
        double output_low_;  ///< lowest value controller can output
};

#endif
