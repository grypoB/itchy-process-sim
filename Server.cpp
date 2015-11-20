#include "Server.h"
#include <iostream>
#include <sstream>

namespace {
    const std::string DEFAULT_NAME("JARVIS.txt");
}

// --------------------------------------------------------------------------
// Constructors / Destructors

Server::Server() : Agent(), fName_(DEFAULT_NAME), file_(fName_.c_str(),
                   std::ios::app), data_name_(0,""), data_() {
    using namespace std;
    
    if (file_.fail()) {
        cout << "Could not open file " << fName_;
        cout << ". The server won't log in a file." << endl;
    }
}

Server::Server(std::string filename) : Agent(), fName_(filename),
                                       file_(fName_.c_str(), std::ios::app),
                                       data_name_(0,"") {
    using namespace std;
    
    if (file_.fail()) {
        cout << "Could not open file " << fName_;
        cout << ". The server won't log in a file." << endl;
    }
}

Server::~Server() {
    if (file_.is_open()) {
        file_.close();
    }
}

// --------------------------------------------------------------------------
// Redefenition of Agent

/**
 * @send the data to the file
 * @see Server::introduce()
 * @see Server::send
 */
void Server::refresh(double time) {
    using namespace std;

    vector<string>::iterator its;

    cout << "t=" << time << "  Server output" << endl;
    
    for (its = data_name_.begin(); its != data_name_.end(); its++) {
        // write down the data if previously setted
        if(data_.find(*its)!=data_.end()) {
		    file_ << data_[*its] << " "; // TODO use iomanip
		    cout << *its << " "  << data_[*its] << endl;
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


// --------------------------------------------------------------------------
// Setters

/**
 * @stock momentarily the data in the containers
 */
void Server::send(std::string legend, double val) {
    data_[legend] = val;
}


/**
 * @initialise the name of the collected data
 */
void Server::introduce(std::vector<std::string> measure_name) {
    using namespace std;
    
    vector<string>::iterator it;
    
    for (it = measure_name.begin(); it != measure_name.end(); it++) {
        data_name_.push_back(*it);
    }

    // TODO Add the content of data_name_ as commentar in files
}
