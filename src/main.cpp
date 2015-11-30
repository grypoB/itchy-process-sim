#include <iostream>
#include <cstdlib>

#include "Simulator.h"
#include "OnOffController.h"
#include "PulsePhenomenon.h"

int main () {
    using namespace std;

    std::cout << "Initialization..." << std::endl;

    Server server("log.csv");
    cout << "Server OK" << endl;
    State s(0.001,0,20);
    cout << "State OK" << endl;
    PulsePhenomenon p(&s, 100., -100, 100, 50, 0, 50, 100);
    p.set_standard_deviation(10);
    cout << "Phenomenon OK" << endl;
    OnOffController c(&s, &server, 50);
    c.set_legend_keys("room temperature",
                       "outside temperature");
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

    sim.run(300,1000);
    
    cout << "----------------------------------------" << endl;
    cout << "Hope you enjoyed the simulation"  << endl;
    cout << "Run >> gnuplot -persist gnuplot.conf << to see the graph of the simulation" << endl;

    return EXIT_SUCCESS;
}
