#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <vector>
#include "Agent.h"

class Simulator {
    public:
        Simulator();

        void addAgent(Agent& agent);
        void run(unsigned int nbTicks, double lenghtTick); // run the agents in the order they were added

    private:
        vector<Agent*> pAgents_;
}

#endif
