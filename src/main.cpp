#include <iostream>
#include <cstdlib>

#include "Simulator.h"
#include "OnOffController.h"
#include "RngPhenomenon.h"

int main () {
    using namespace std;

    std::cout << "Initialization..." << std::endl;

    Server server("tatf.dat");
    cout << "Server OK" << endl;
    State s(0.001,.01,20);
    cout << "State OK" << endl;
    RngPhenomenon p(&s, 10, 30);
    cout << "Phenomenon OK" << endl;
    OnOffController c(&s, &server, 15);
    c.set_legend_keys("room temperature",
                       "outside temperature",
                       "cooler");
    cout << "Controller OK" << endl;
    Simulator sim;
    cout << "Sim OK" << endl;

    cout << endl << "Fasten yout seatbelt" << endl;

    sim.addAgent(p);
    sim.addAgent(c);
    sim.addAgent(s);
    sim.addAgent(server);

    cout << "Here we go" << endl;
    cout << "----------------------------------------" << endl << endl;

    sim.run(60*60,100);
    
    cout << "----------------------------------------" << endl;
    cout << "Hope you enjoyed the simulation"  << endl;
    cout << "Run >> gnuplot gnuplot.conf -p << to see the graph of the simulation" << endl;

    return EXIT_SUCCESS;
}
