#ifndef RNGPHENOMENON_H_
#define RNGPHENOMENON_H_

#include "Phenomenon.h"

class RngPhenomenon: public Phenomenon {
    public:
        RngPhenomenon();
        RngPhenomenon(State* pState, double min, double max);

        virtual ~RngPhenomenon();
    private:
        double min_;
        double max_;
    protected:
        virtual double gen_val_phen(double time);
};

#endif
