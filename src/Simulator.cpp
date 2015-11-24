#include "Simulator.h"
#include <cstddef>

Simulator::Simulator() : pAgents_(0,NULL) {}

/** Adds agent to refresh durign the simulation
 *  @see Simulator::run
 */
void Simulator::addAgent(Agent& agent) {
    pAgents_.push_back(&agent);
}

/** Runs a simulation
 * @desc For each ticks, calls Agent::refresh for each agent,
 *       before starting the simulation calls Agent::init.
 *       The call order is the order they were added
 * @see Simulator::addAgent
 * @param simDuration ammount of time of the total simulation
 * @param nbTicks Number of simulation ticks to do
 */
void Simulator::run(double simDuration, unsigned int nbTicks) {
	double lenghtTick(simDuration/nbTicks);
    double time(lenghtTick); // begin at t=lenghtTick>0

    for (unsigned int i=0 ; i<pAgents_.size() ; i++) {
        pAgents_.at(i)->init(); // equivalent to t=0
    }

    for (unsigned int i=0 ; i<nbTicks ; i++) {
        for (unsigned int j=0 ; j<pAgents_.size() ; j++) {
            pAgents_.at(j)->refresh(time);
        }
        time += lenghtTick;
    }
}
