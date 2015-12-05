#include <iostream>
#include <cstdlib>

#include "Simulator.h"
#include "OnOffController.h"
#include "SinPhenomenon.h"

int main () {
    using namespace std;

    std::cout << "Initialization..." << std::endl;

    Server server("log.csv");
    cout << "Server OK" << endl;
    State s(0.1,0.1,20);
    cout << "State OK" << endl;
    SinPhenomenon p(&s, 100., 0., 20.,0., -1000., 1000.);
    //p.set_standard_deviation(1);
    cout << "Phenomenon OK" << endl;
    OnOffController c(&s, &server, 0 ,10,20,-20);
    c.set_legend_keys("room temperature",
                       "outside temperature",
                       "controller");
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
