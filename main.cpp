#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "Simulator.h"
#include "Controller.h"
#include "Phenomenon.h"

int main (int argc, char *argv[]) {
    using namespace std;

    std::cout << "Initialization..." << std::endl;

    Server server;
    cout << "Server OK" << endl;
    State s(1,0,0);
    cout << "State OK" << endl;
    Phenomenon p(&s, -1, 100);
    cout << "Phenomenon OK" << endl;
    Controller c(&s, &server);
    cout << "Controller OK" << endl;
    Simulator sim;
    cout << "Sim OK" << endl;

    cout << endl << "Fasten yout seatbelt" << endl;
    
    sim.addAgent(p);
    sim.addAgent(s); // TODO invert to not have the actual value to server bu t-1
    sim.addAgent(c);
    sim.addAgent(server);

    cout << "Here we go" << endl;
    cout << "----------------------------------------" << endl << endl;

    sim.run(10,1.1);

    return EXIT_SUCCESS;
}
