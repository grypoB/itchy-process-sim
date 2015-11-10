#include <cassert>

Simulator::Simulator() : pAgents(0,0) {}

void addAgent(Agent& agent) {
    pAgents_.push_back(agent);
}

void run(unsigned int nbTicks, double lenghtTick) {
    double time(.0);

    for (int i=0 ; i<nbTicks ; i++) {
        for (int j=0 ; j<pAgents_.size() ; j++) {
            pAgents_.at(j)->run(time);
        }
        time += lenghtTick;
    }
}
