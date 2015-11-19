#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <vector>
#include "Agent.h"

class Simulator {
    public:
        Simulator();

        void addAgent(Agent& agent);
        void run(unsigned int nbTicks, double lenghtTick);

    private:
        std::vector<Agent*> pAgents_; // Agent the simulator has to run
};

#endif
