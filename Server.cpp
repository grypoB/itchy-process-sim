#include "Server.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

const std::string DEFAULT_NAME("JARVIS.txt");

std::string double_to_string(double val);

Server::Server() : Agent(), fName_(DEFAULT_NAME), file_(fName_.c_str(), std::ios::app), data_name_(0,""), data_() { // TODO default constructor for data_ ?
    if (file_.fail()) {
        std::cout << "Could not open file " << fName_ << ". The server won't log in a file." << std::endl;
    }
}

Server::Server(std::string filename) : Agent(), fName_(filename), file_(fName_.c_str(), std::ios::app), data_name_(0,"") {// TODO default constructor for data_ ?
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

    vector<string>::iterator its;

    cout << "t=" << time << "  Server output" << endl;

    for (its = data_name_.begin(); its != data_name_.end(); its++) {
        if(data_.find(*its)!=data_.end()) {
		    file_ << data_[*its] << " "; // TODO use iomanip
		    cout << *its << " "  << data_[*its] << endl; // TODO use iomanip
		}
		else {
            file_ << "- ";
            cout << "- ";
        }
    }
    file_ << endl; 
    cout << endl; 

    data_.clear();
}

void Server::send(std::string legend, double val) {
    data_[legend] = val; 
}

void Server::introduce(std::vector<std::string> measure_name) {
    using namespace std;
    
    for (vector<string>::iterator it = measure_name.begin() ; it != measure_name.end(); it++) {
        data_name_.push_back(*it);
        data_[*it];
    }

    // TODO Add the content of data_name_ as commentar in files
}


std::string double_to_string(double val) {
    using namespace std;

    ostringstream oss;

    oss << val;

    return oss.str();
}
