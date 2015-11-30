#ifndef PULSEPHENOMENON_H_
#define PULSEPHENOMENON_H_

#include "Phenomenon.h"

class PulsePhenomenon: public Phenomenon {
    public:
        PulsePhenomenon();
        PulsePhenomenon(State* pState, double low, double high, double delay,
                        double rise, double p_width, double fall, double period);
        virtual ~PulsePhenomenon();
    private:
        double val_low_; ///< minimum value
        double val_high_; ///< maximium value
        double t_delay_; ///< time before the first rise begins
        double t_rise_; ///< time it takes to go form the lowest to the highest value
        double p_high_; ///< time phenomenon keep the highest value
        double t_fall_; ///< time it takes to go from the highest to the lowest value
        double period_;

    protected:
        virtual double gen_val_phen(double time);
};

#endif
