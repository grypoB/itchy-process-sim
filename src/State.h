#ifndef STATE_H_
#define STATE_H_

#include "Agent.h"

class State: public Agent {
    public:
        State(double i_phen, double i_ctrl, double init_state_val, 
              double val_state_min, double val_state_max);
        virtual ~State();

        virtual void refresh(double time);
        virtual void init();

        void set_val_phen(double val_phen);
        void set_val_ctrl(double val_phen);

        double get_val_phen() const;
        double get_val_state() const;
        double get_val_ctrl() const;

    private:
        const double i_phen_; ///< influence factor of phenomenom in [1/time]
        const double i_ctrl_; ///< influence factor of controller in [1/time]
        const double val_state_min_; ///< minimum value of the state can have
        const double val_state_max_; ///< maximum value of the state can have

        double val_phen_;  ///< value of phenomenon influencing the state
        double val_ctrl_;  ///< value of the controller influencing the state
        double val_state_; ///< current value of the state

        double prevTime_; ///< time at which refresh was last called
};

#endif
