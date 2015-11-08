/*
 * Controller.h
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "State.h"

namespace controller {

class Controller {
public:
	Controller();
	virtual ~Controller();

	void update_ctrl ();

private:
	Server* server_;
	State* state_;

};

} /* namespace controller */

#endif /* CONTROLLER_H_ */
