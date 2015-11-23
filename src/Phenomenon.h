#ifndef PHENOMENON_H_
#define PHENOMENON_H_

#include "State.h"

class Phenomenon: public Agent{
    public:
        Phenomenon();
        Phenomenon(State* pState); ///< Initialize a phenomenon influencing a state
        virtual ~Phenomenon();

        virtual void refresh(double time); ///< Apply phenomenon value to state

    private:
        State* const pState_; ///< state to influence

    protected:
        virtual double gen_val_phen(double time)=0; ///< Phenomenon value in function of time
};

#endif
