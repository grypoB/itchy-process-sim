/** @file main author : Guillaume Duc & Alexandre Devienne **/

#ifndef SERVER_H_
#define SERVER_H_

#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "Agent.h"

/** Constants used by Server constructor
 */
namespace ServerConst {

    const std::string DEFAULT_NAME("JARVIS.txt");
    const std::string DEFAULT_GNUPLOT_CONF("gnuplot.conf");
}

class Server: public Agent {
    public:
        /** Create a server which will output simulation data in given the 
         * filename*/
        Server(std::string filename = ServerConst::DEFAULT_NAME,
               std::string gnuplotConfName = ServerConst::DEFAULT_GNUPLOT_CONF);
        ~Server();

        virtual void refresh(double time);
        virtual void init();

        void send(std::string legend, double val);
        void introduce(std::vector<std::string> mesure_name);

    private:
        std::string fName_; ///< name of output file to be used by gnuplot
        std::string gnuplotConfName_; ///< name of config file to be used by gnuplot
        std::ofstream file_; ///< output stream for writting in fName_
        std::vector<std::string> data_name_; ///< name of th data to output
        std::map<const std::string, double> data_; ///< buffer of sent data
};

#endif
