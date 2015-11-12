/*
 * Controller.h
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "State.h"
#include "Server.h"
#include "Agent.h"

class Controller: public Agent {
    public:
        Controller();
        Controller(State* pState, Server* pServer);
        virtual ~Controller();

        virtual void refresh(double time);

    private:
        State*  pState_;
        Server* pServer_;
};

#endif /* CONTROLLER_H_ */
