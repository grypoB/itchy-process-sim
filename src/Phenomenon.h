#ifndef PHENOMENON_H_
#define PHENOMENON_H_

#include "State.h"


namespace Phen {
    const double DEFAULT_SIGMA(.0); // standard deviation
}

class Phenomenon: public Agent{
    public:
        Phenomenon(State* pState); ///< Initialize a phenomenon influencing a state
        virtual ~Phenomenon();

        void set_standard_deviation(double sigma);
        virtual void refresh(double time); ///< Apply phenomenon value to state

    private:
        State* const pState_; ///< state to influence
        /* sigma of the normal distribution of the noise to apply to the phenomenon output */
        double standard_deviation_;
    protected:
        virtual double gen_val_phen(double time)=0; ///< Phenomenon value in function of time
};

#endif
