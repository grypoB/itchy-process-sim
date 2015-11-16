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
        std::string fName_;
        std::ofstream file_;
        std::vector<std::string> data_name_;
        std::map<const std::string, double> data_;
};

#endif /* SERVER_H_ */
