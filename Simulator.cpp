#include "Simulator.h"
#include <cassert>

Simulator::Simulator() : pAgents_(0,0) {}

void Simulator::addAgent(Agent& agent) {
    pAgents_.push_back(&agent);
}

void Simulator::run(unsigned int nbTicks, double lenghtTick) {
    double time(.0);

    for (unsigned int i=0 ; i<pAgents_.size() ; i++) {
        pAgents_.at(i)->init();
    }

    for (unsigned int i=0 ; i<nbTicks ; i++) {
        for (unsigned int j=0 ; j<pAgents_.size() ; j++) {
            pAgents_.at(j)->refresh(time);
        }
        time += lenghtTick;
    }
}
