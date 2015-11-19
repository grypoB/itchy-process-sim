#ifndef SERVER_H_
#define SERVER_H_

#include "Agent.h"
#include <string>
#include <vector>
#include <fstream>
#include <map>

class Server: public Agent {
    public:
        Server();
        Server(std::string filename);
        ~Server();

        virtual void refresh(double time);

        void send(std::string legend, double val);
        void introduce(std::vector<std::string> mesure_name);
        

    private:
        std::string fName_;                         // name of the data file
        std::ofstream file_;                        // output stream for writting data to a file
        std::vector<std::string> data_name_;        // name of the data
        std::map<const std::string, double> data_;  // container of data
};

#endif /* SERVER_H_ */
