#include <iostream>
#include <cstdlib>

#include "xml_parser.h"
#include "Simulator.h"
#include "OnOffController.h"
#include "SinPhenomenon.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>

int main (int argc, char *argv[]) {
    using namespace std;

    string inputXml("xml/sim.xml");

    if (argc==2) {
        inputXml = argv[1];
    }

    try{

        std::cout << "Initialization..." << std::endl;
        xml_parser(inputXml);
        cout << "Here we go" << endl;
        cout << "----------------------------------------" << endl << endl;
        cout << "----------------------------------------" << endl;
        cout << "Hope you enjoyed the simulation"  << endl;
        cout << "Run >> gnuplot -persist gnuplot.conf << to see the graph of the simulation" << endl;

    } catch (string &s) {
        cout << "ERROR" << endl << endl;
        cout << "ERROR: " << s << endl;
    }

    /*
    Server server("log.csv");
    cout << "Server OK" << endl;
    State s(0.1,0.1,20);
    cout << "State OK" << endl;
    SinPhenomenon p(&s, 100., 50.);
    p.set_standard_deviation(10);
    cout << "Phenomenon OK" << endl;
    OnOffController c(&s, &server, 0 ,10,30,-30);
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
    */

    return EXIT_SUCCESS;
}
