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

class Controller {
public:
	Controller();
	Controller(State* pState, Server* pServer, double val_start, double val_stop);
	virtual ~Controller();

	void refresh (double time);

private:
	State* pState_;
	Server* pServer_;
	
	const double val_start_;
	const double val_stop_;

};

#endif /* CONTROLLER_H_ */
