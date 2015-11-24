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
        
        void set_legend(std::vector<std::string> legend);

    private:
        State*  pState_; ///< State to control
        Server* pServer_; ///< Server to send data too
        std::vector<std::string> legend_keys_; ///< Name of the agents for the server

    protected:
        double get_info_state();
        void transmit();
        void send_val_ctrl_to_server(double val);
};

#endif
