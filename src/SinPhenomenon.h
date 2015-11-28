#ifndef SINPHENOMENON_H_
#define SINPHENOMENON_H_

#include "Phenomenon.h"

class SinPhenomenon: public Phenomenon {
    public:
        SinPhenomenon();
		SinPhenomenon(State* pState, double min, double max, double period,
                                  double offset, double ampl, double phase, double sat_min,
                                  double sat_max);
        virtual ~SinPhenomenon();
    private:
        double min_; ///< minimum of random value
        double max_; ///< maximium of random value
        double previous_time_; ///< keep in mind the previous time
        double period_;
        double offset_;
        double ampl_; ///< amplitude of the sinusoid
        double phase_;
        double sat_min_; ///< minimum of phenomenon value
        double sat_max_; ///< maximum of phenomenon value
    protected:
        virtual double gen_val_phen(double time);
};

#endif
