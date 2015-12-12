/** @file
 *  @author Guillaume Duc **/

#ifndef PULSEPHENOMENON_H_
#define PULSEPHENOMENON_H_

#include "Phenomenon.h"

/** Constant used by the PulsePhenomenon constructor
 * @see PulsePhenomenon
 */
namespace  PulsePhen{
    const double DEFAULT_DELAY(0.);
    const double DEFAULT_RISE(0.);
    const double DEFAULT_FALL(0.);
}


class PulsePhenomenon: public Phenomenon {
    public:
        PulsePhenomenon(State* pState, double low, double high,
                        double p_width, double period,
                        double rise = PulsePhen::DEFAULT_RISE,
                        double fall = PulsePhen::DEFAULT_FALL,
                        double delay= PulsePhen::DEFAULT_DELAY);
        virtual ~PulsePhenomenon();
    private:
        double val_low_;  ///< low value of the pulse
        double val_high_; ///< high value of the pulse
        double t_delay_;  ///< time before the first rise begins
        double t_rise_;   ///< time it takes to go form the lowest to the highest value
        double p_high_;   ///< time phenomenon keeps the highest value
        double t_fall_;   ///< time it takes to go from the highest to the lowest value
        double period_;   ///< period of the pulse

    protected:
        virtual double gen_val_phen(double time);
};

#endif
