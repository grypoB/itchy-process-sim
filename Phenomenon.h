/*
 * Phenomenon.h
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#ifndef PHENOMENON_H_
#define PHENOMENON_H_

#include "State.h"

class Phenomenon: public Agent{
    public:

        Phenomenon();
        Phenomenon(State* pState);
        virtual ~Phenomenon();

        virtual void refresh(double time);

    private:
        State* const pState_;

    protected:
        virtual double gen_val_phen(double time)=0;
};

#endif /* PHENOMENON_H_ */
