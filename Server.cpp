#include "Server.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

const std::string DEFAULT_NAME("JARVIS.txt");

std::string double_to_string(double val);

Server::Server() : fName_(DEFAULT_NAME), file_(fName_.c_str(), std::ios::app), data_name_(0,""), data_() { // TODO default constructor for data_ ?
    if (file_.fail()) {
        std::cout << "Could not open file " << fName_ << ". The server won't log in a file." << std::endl;
    }
}

Server::Server(std::string filename) : fName_(filename), file_(fName_.c_str(), std::ios::app), data_name_(0,"") {// TODO default constructor for data_ ?
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
    
    map<string,double>::iterator itm;
    
    cout << "t=" << time << "  Server output" << endl;
    
    for (vector<string>::iterator its = data_name_.begin() ; its != data_name_.end(); its++) {
        
        if(data_.find(*its)!=data_.end()) {
		    file_ << itm->second << + "\t"; // TODO use iomanip
		}

		else {
            file_ << " - \t";
        }
    }
        
    data_.clear();
}

void Server::send(std::string legend, double val) {
    using namespace std;
    
    map<string,double>::iterator it;
    
    it = data_.find(legend);
    it->second = val;
}

void Server::introduce(std::vector<std::string> mesure_name) {
    using namespace std;
    
    for (vector<string>::iterator it = mesure_name.begin() ; it != mesure_name.end(); it++) {
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
