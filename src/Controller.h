/** @file main author : Guillaume Duc **/

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "State.h"
#include "Server.h"

class Controller: public Agent {
    public:
        Controller(State* pState, Server* pServer);
        virtual ~Controller();

        virtual void refresh(double time);
        virtual void init();

        void set_legend_keys(std::string legendState,
                             std::string legendPhen= "",
                             std::string legendCtrl= "");

        void set_boundaries(double val_ctrl_min, double val_ctrl_max);
        void set_refresh_rate(double deltaT);

    private:
        double val_ctrl_min_; ///< max possible value to output
        double val_ctrl_max_; ///< min possible value to output

    protected:
        State*  pState_; ///< State to control
        Server* pServer_; ///< Server to send data too
        std::vector<std::string> legend_keys_; ///< Name of the agents for the server

        double lastOutput_; ///< store the last value the controller outputed (used for the refresh rate)
        double lastTime_; ///< last time the controller took a descision
        double refreshRate_; ///< how fast the controller should take descisions

        /** retrun how the controller respond, should be reimplement in child
         * classes
         */
        virtual double getResponse(double time, double val_state, double val_phen);

};

#endif
