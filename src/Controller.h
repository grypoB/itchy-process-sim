#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <vector>
#include <string>

#include "State.h"
#include "Server.h"

class Controller: public Agent {
    public:
        Controller();
        Controller(State* pState, Server* pServer);
        virtual ~Controller();

        virtual void refresh(double time);
        virtual void init();
        
        void set_legend_keys(std::string legendState,
                             std::string legendPhen= "",
                             std::string legendCtrl= "");

    protected:
        State*  pState_; ///< State to control
        Server* pServer_; ///< Server to send data too
        std::vector<std::string> legend_keys_; ///< Name of the agents for the server

        /** retrun how the controller respond, should be reimplement in child
         * classes
         */
        virtual double getResponse(double time, double valState, double valPhen);

};

#endif
