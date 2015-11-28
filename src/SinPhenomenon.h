#ifndef SINPHENOMENON_H_
#define SINPHENOMENON_H_

#include "Phenomenon.h"

class SinPhenomenon: public Phenomenon {
    public:
        SinPhenomenon();
		SinPhenomenon(State* pState, double period, double offset, double ampl, double phase,
                      double sat_min, double sat_max);
        virtual ~SinPhenomenon();
    private:
        double period_;
        double offset_;
        double ampl_; ///< amplitude of the sinusoid
        double phase_;
        double sat_min_; ///< lowest value the phenomenon can take
        double sat_max_; ///< highest value the phenomenon can take
    protected:
        virtual double gen_val_phen(double time);
};

#endif
