#ifndef SERVER_H_
#define SERVER_H_

#include "Agent.h"
#include <string>
#include <vector>
#include <fstream>

class Server: public Agent {
    public:
        Server();
        Server(std::string filename);
        ~Server();

        virtual void refresh(double time);

        // stub for com protocol
        void send(std::string legend, double val);

    private:
        std::vector<std::string> buffer_;
        std::string fName_;
        std::ofstream file_;
};

#endif /* SERVER_H_ */
