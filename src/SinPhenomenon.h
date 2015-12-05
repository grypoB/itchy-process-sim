#ifndef SINPHENOMENON_H_
#define SINPHENOMENON_H_

#include "Phenomenon.h"

/** Constants used by the SinPhenomenon constructor
 * @see SinPhenomenon
 */
namespace SinPhen {
    const double DEFAULT_OFFSET(0.);
    const double DEFAULT_PHASE(0.);
    const double MIN_PERIOD(1e-9); ///< Minimum period size
}

class SinPhenomenon: public Phenomenon {
    public:
		SinPhenomenon(State* pState, double amplitude, double period,
                      double offset = SinPhen::DEFAULT_OFFSET,
                      double phase = SinPhen::DEFAULT_PHASE);
        
        virtual ~SinPhenomenon();
    private:
        double period_; ///< period of the sine wave
        double offset_; ///< offset of the sine wave
        double ampl_; ///< amplitude of the sinusoid
        double phase_; ///< phase in radian of the sine
    protected:
        virtual double gen_val_phen(double time);
};

#endif
