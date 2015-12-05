#ifndef RNGPHENOMENON_H_
#define RNGPHENOMENON_H_

#include "Phenomenon.h"

class RngPhenomenon: public Phenomenon {
    public:
        RngPhenomenon(State* pState, double min, double max);
        virtual ~RngPhenomenon();
    private:
        double min_; ///< minimum of phenomenon value
        double max_; ///< maximium of phenomenon value
    protected:
        virtual double gen_val_phen(double time);
};

#endif
