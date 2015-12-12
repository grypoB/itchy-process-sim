#include <string>
#include "Simulator.h"

Simulator::Simulator() : pAgents_(0) {}

/** Adds agent to refresh during the simulation
 *  @see Simulator::run
 */
void Simulator::addAgent(Agent& agent) {
    pAgents_.push_back(&agent);
}

/** Runs a simulation
 *
 *   For each ticks, calls Agent::refresh for each agent,
 *       before starting the simulation calls Agent::init.
 *       The call order is the order they were added
 * @see Simulator::addAgent
 * @param simDuration ammount of time of the total simulation
 * @param nbTicks Number of simulation ticks to do
 */
void Simulator::run(double simDuration, int nbTicks) {
	double lenghtTick(simDuration/nbTicks);
    double time(lenghtTick); // begin at t=lenghtTick>0

    if (simDuration < 0) {
        throw std::string ("The duration used in simulator is negative");
    }
    
    if (nbTicks < 0) {
        throw std::string ("The number of steps in the simulation is negative");
    }

    for (unsigned int i=0 ; i<pAgents_.size() ; i++) {
        pAgents_[i]->init(); // equivalent to t=0
    }

    for (int i=0 ; i<nbTicks ; i++) {
        for (unsigned int j=0 ; j<pAgents_.size() ; j++) {
            pAgents_[j]->refresh(time);
        }
        time += lenghtTick;
    }
}
