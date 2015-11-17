#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "Simulator.h"
#include "Controller.h"
#include "RngPhenomenon.h"

int main (int argc, char *argv[]) {
    using namespace std;

    std::cout << "Initialization..." << std::endl;

    Server server("tata.dat");
    cout << "Server OK" << endl;
    State s(1,0,0);
    cout << "State OK" << endl;
    RngPhenomenon p(&s, -1, 100);
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

    sim.run(10,1.1);

    return EXIT_SUCCESS;
}
