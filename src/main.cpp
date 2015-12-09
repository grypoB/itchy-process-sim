/** @file main author : Alexandre Devienne **/

#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "xml_parser.h"

int main (int argc, char *argv[]) {
    using namespace std;

    string inputXml("xml/sim.xml");

    if (argc==2) {
        inputXml = argv[1];
    }

    try{

        std::cout << "Initialization..." << std::endl;
        xml_parser(inputXml);
        cout << "Hope you enjoyed the simulation"  << endl;
        cout << "Run >> gnuplot -persist gnuplot.conf << to see the graph of the simulation" << endl;

    } catch (string &s) {
        cout << "ERROR" << endl << endl;
        cout << "ERROR: " << s << endl;
    }

    return EXIT_SUCCESS;
}
