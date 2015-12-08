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

        cout << "=========================================" << endl;
        xml_parser(inputXml);
        cout << "=========================================" << endl;

        cout << endl << endl;
        cout << "Run the following command to see the results of the simulation :" << endl;
        cout << "$ gnuplot -persist gnuplot.conf" << endl;
        cout << "You might want another visualization of the simulation tough." << endl;
        cout << "Goodbye." << endl;

    } catch (string &s) {
        cout << "ERROR" << endl << endl;
        cout << "ERROR: " << s << endl;
    }

    return EXIT_SUCCESS;
}
