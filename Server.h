#ifndef SERVER_H_
#define SERVER_H_

#include "Agent.h"
#include <string>
#include <vector>
#include <fstream>
#include <map>

class Server: public Agent {
    public:
        Server(); ///< Create a fonctionning server with default output file
        /** Create a server which will output simulation data in given the 
         * filename*/
        Server(std::string filename); 
        ~Server();

        virtual void refresh(double time);

        void send(std::string legend, double val);
        void introduce(std::vector<std::string> mesure_name);

    private:
        std::string fName_; ///< name of output file to be used by gnuplot
        std::ofstream file_; ///< output stream for writting in fName_
        std::vector<std::string> data_name_; ///< name of th data to output
        std::map<const std::string, double> data_; ///< buffer of sent data
};

#endif
