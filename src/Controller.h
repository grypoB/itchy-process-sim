#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "State.h"
#include "Server.h"

class Controller: public Agent {
    public:
        Controller();
        Controller(State* pState, Server* pServer);
        virtual ~Controller();

        virtual void refresh(double time);
        virtual void init();

    private:
        State*  pState_; ///< State to control
        Server* pServer_; ///< Server to send data too
};

#endif
