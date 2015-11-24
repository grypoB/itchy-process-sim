#include <iostream>
#include <cstdlib>

#include "Simulator.h"
#include "Controller.h"
#include "RngPhenomenon.h"

int main () {
    using namespace std;

    std::cout << "Initialization..." << std::endl;

    Server server("tatf.dat");
    cout << "Server OK" << endl;
    State s(0.0001,.0,0);
    cout << "State OK" << endl;
    RngPhenomenon p(&s, 900, 1000);
    cout << "Phenomenon OK" << endl;
    Controller c(&s, &server);
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

    sim.run(24*60*60,10);
    
    cout << "----------------------------------------" << endl;
    cout << "Hope you enjoyed the simulation"  << endl;
    cout << "Run >> gnuplot gnuplot.conf -p << to see the graph of the simulation" << endl;

    return EXIT_SUCCESS;
}
