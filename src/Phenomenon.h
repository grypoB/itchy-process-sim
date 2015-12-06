#ifndef PHENOMENON_H_
#define PHENOMENON_H_

#include "State.h"

class Phenomenon: public Agent{
    public:
        Phenomenon(State* pState); ///< Initialize a phenomenon influencing a state
        virtual ~Phenomenon();

        virtual void refresh(double time); ///< Apply phenomenon value to state
        void set_standard_deviation(double sigma);
        void set_boundaries(double val_phen_min, double val_phen_max);

    private:
        State* const pState_; ///< state to influence
        /* sigma of the normal distribution of the noise to apply to the phenomenon output */
        double standard_deviation_;
        double val_phen_min_; ///< minimum value the phenomenon can have 
        double val_phen_max_; ///< maximum value the phenomenon can have
    protected:
        virtual double gen_val_phen(double time)=0; ///< Phenomenon value in function of time
};

#endif
