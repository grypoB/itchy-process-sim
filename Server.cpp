#include "Server.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

const std::string DEFAULT_NAME("JARVIS.txt");

std::string double_to_string(double val);

Server::Server() : buffer_(0,""), fName_(DEFAULT_NAME), file_(fName_.c_str(), std::ios::app) {
    if (file_.fail()) {
        std::cout << "Could not open file " << fName_ << ". The server won't log in a file." << std::endl;
    }
}

Server::Server(std::string filename) : buffer_(0,""), fName_(filename), file_(fName_.c_str(), std::ios::app) {
    if (file_.fail()) {
        std::cout << "Could not open file " << fName_ << ". The server won't log in a file." << std::endl;
    }
}

Server::~Server() {
    if (file_.is_open()) {
        file_.close();
    }
}

void Server::refresh(double time) {
    using namespace std;
    
    cout << "t=" << time << "  Server output" << endl;
    for (unsigned int i=0 ; i<buffer_.size() ; i++) {
        cout << buffer_.at(i) << endl;
        if(file_.is_open()) {file_ << buffer_.at(i) << endl; }
    }
        
        buffer_.clear();
}

void Server::send(std::string legend, double val) {
    
    // TODO how sort the data for gnuplot ?
    buffer_.push_back(legend + " " + double_to_string(val));
}

void Server::introduce(std::vector<std::string> mesure_name) {
    using namespace std;
    
    for (vector<string>::iterator it = mesure_name.begin() ; it != mesure_name.end(); it++) {
        data_name_.push_back(*it);
    }
}


std::string double_to_string(double val) {
    using namespace std;
    ostringstream oss;
    
    oss << val;
    
    return oss.str();
}
