#include <iostream>
#include <sstream>
#include "Server.h"

namespace {
    const std::string TIME("t");
}

// Server with specified filename
Server::Server(std::string filename, std::string gnuplotConfName)
               : Agent(), fName_(filename), gnuplotConfName_(gnuplotConfName),
                 file_(fName_.c_str(), std::ios::trunc),
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


/** Add header to output file
 * and create corresponding config file for gnuplot
 *
 * Needs to be called after Server::introduce
 */
void Server::init() {
    using namespace std;

    ofstream conf(gnuplotConfName_.c_str(), std::ios::trunc); // replace before conf

    if (conf.is_open() && file_.is_open()) {
        // create commentary at the beginning of the output file
        // and creat conf file
        file_ << "# ";
        file_.precision(15);
        data_name_.insert(data_name_.begin(), TIME);
        for (unsigned int i=0; i<data_name_.size() ; i++) {
            file_ << data_name_.at(i) << " ";

            if (i==0) { // i==0 represent data_name_=time
                conf << "plot";
            } else {
                conf << " \""<< fName_ << "\" using 1:" << i+1 << " title \"" << data_name_.at(i) << "\"";
                if (i+1<data_name_.size()) { // if not last value to plot
                    conf << ", \\" << endl;
                }
            }
            
        }
        file_ << endl;
        conf << endl;
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
    data_[TIME] = time;

    //cout << "t=" << time << "  Server output" << endl;

    for (its = data_name_.begin(); its != data_name_.end(); its++) {
        // write down the data if previously setted
        if(data_.find(*its)!=data_.end()) {
		    file_ << data_[*its] << ", ";
		    //cout << *its << " "  << data_[*its] << endl;
		}
		else {
            file_ << "- ";
            //cout << *its << "- " << endl;
        }
    }
    file_ << endl;
    //cout << endl;

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
        if (it->compare("") != 0) { // check if non-empty
            data_name_.push_back(*it);
            cout << "introduced " << *it << endl;
        }
    }
}
