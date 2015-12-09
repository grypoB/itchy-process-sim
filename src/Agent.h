/** @file main author : Alexandre Devienne **/

#ifndef AGENT_H_
#define AGENT_H_


class Agent {
    public:
        Agent() {};
        virtual ~Agent() {};
        virtual void refresh(double time)=0; ///< ask the agent to update itself at t=time
        virtual void init() {} ///< run a at the beginning of the sim to init all parameter/relationship
};

#endif
