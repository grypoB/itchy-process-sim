/*
 * State.h
 *
 *  Created on: Nov 2, 2015
 *      Author:
 */

#ifndef STATE_H_
#define STATE_H_

#include "Agent.h"

class State: public Agent {
    public:
        State();
        State(double i_phen, double i_ctrl, double eff_state);
        virtual ~State();

        void refresh(double time);

        void set_val_phen(double val_phen);
        void set_val_ctrl(double val_phen);

        double get_val_phen() const;
        double get_val_state() const;
        double get_val_ctrl() const;

    private:

        const double i_phen_; // influence factor of phenomenom in [1/s]
        const double i_ctrl_; // influence factor of controller in [1/s]

        double val_phen_;
        double val_ctrl_;
        double eff_state_;
};

#endif /* STATE_H_ */
