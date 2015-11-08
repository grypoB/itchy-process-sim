/*
 * Aera.h
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#ifndef AERA_H_
#define AERA_H_

#include "Phenomenon.h"
#include "State.h"
#include "Controller.h"
#include "Server.h"

namespace aera {

class Aera {
public:
	Aera();
	virtual ~Aera();

private:

	Phenomenon phen_;
	State state_;
	Controller ctrl_;
	Server* server_;

};

} /* namespace aera */

#endif /* AERA_H_ */
