#include "Server.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

const std::string DEFAULT_NAME("JARVIS");

std::string double_to_string(double val);

Server::Server() : buffer_(0,""), name_(DEFAULT_NAME) {}


void Server::refresh(double time) {
    using namespace std;
    static string dest_file(name_+".txt");
    ofstream f_dest(dest_file.c_str(), ios::app); // add the data at the end of the file
    
    cout << "t=" << time << "  Server output" << endl;
     
    if (f_dest) {
        for (unsigned int i=0 ; i<buffer_.size() ; i++) {
            cout << buffer_.at(i) << endl;
            f_dest << buffer_.at(i) << endl;
        }
        
        buffer_.clear();
        f_dest.close();
    }
    
    else {
        cout << "Erreur d'ouverture de fichier" << endl;
    }
}

void Server::send(std::string legend, double val) {
    // TODO how sort the data for gnuplot ?
    buffer_.push_back(legend + " " + double_to_string(val));
}




std::string double_to_string(double val) {
    using namespace std;
    ostringstream oss;
    
    oss << val;
    
    return oss.str();
}
