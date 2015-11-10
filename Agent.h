#ifndef AGENT_H_
#define AGENT_H_


class Agent {
    public:
        virtual void refresh(double time)=0; // run the agent at t=time
};

#endif
