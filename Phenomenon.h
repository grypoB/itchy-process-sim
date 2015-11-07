/*
 * Phenomenon.h
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#ifndef PHENOMENON_H_
#define PHENOMENON_H_

namespace Phenomenon {

class Phenomenon {
public:
	Phenomenon();
	virtual ~Phenomenon();

	double get_val_phen () const;

	void update_val_phen ();

private:
	double val_phen_;
};

} /* namespace Phenomenon */

#endif /* PHENOMENON_H_ */
