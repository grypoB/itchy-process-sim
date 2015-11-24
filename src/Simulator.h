#ifndef SIMULATOR_H_
#define SIMULATOR_H_

#include <vector>
#include "Agent.h"

class Simulator {
    public:
        Simulator();

        void addAgent(Agent& agent);
        void run(double simDuration, unsigned int nbTicks);

    private:
        std::vector<Agent*> pAgents_; ///< Agents the simulator has to run
};

#endif
