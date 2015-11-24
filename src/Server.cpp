#include "Server.h"
#include <iostream>
#include <sstream>

namespace {
    const std::string DEFAULT_NAME("JARVIS.txt");
}

// Default server
Server::Server() : Agent(), fName_(DEFAULT_NAME), file_(fName_.c_str(),
                   std::ios::app), data_name_(0,""), data_() {
    using namespace std;

    if (file_.fail()) {
        cout << "Could not open file " << fName_;
        cout << ". The server won't log in a file." << endl;
    }
}

// Server with specified filename
Server::Server(std::string filename) : Agent(), fName_(filename),
                                       file_(fName_.c_str(), std::ios::app),
                                       data_name_(0,""), data_() {
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


/** Output recorded data to cout and file
 *
 * The file will be formated correctly for gnuplot to parse
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
		    file_ << data_[*its] << " ";
		    cout << *its << " "  << data_[*its] << endl;
		}
		else {
            file_ << "- ";
            cout << *its << "- " << endl;
        }
    }
    file_ << endl;
    cout << endl;

    data_.clear();
}


/** Store info in a buffer for future output in refresh
 *
 * Data are stored in pairs : (legend, val). Sending a val with the same
 * legend key will overidde the previous sent value.
 * The buffer is cleared after each refresh.
 * @see Server::refresh
 */
void Server::send(std::string legend, double val) {
    data_[legend] = val;
}


/** Initialize order and legend key of the data to output in refresh
 * @param measure_name Vector containing the legend key which will be outputed.
 *                     The order they are in the vector is the order they will
 *                     be outputed.
 * @see Server::send
 */
void Server::introduce(std::vector<std::string> measure_name) {
    using namespace std;

    vector<string>::iterator it;

    for (it = measure_name.begin(); it != measure_name.end(); it++) {
        data_name_.push_back(*it);
    }

}
