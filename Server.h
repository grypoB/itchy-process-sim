#ifndef SERVER_H_
#define SERVER_H_

#include "Agent.h"
#include <string>
#include <vector>

class Server: public Agent {
    public:
        Server();

        virtual void refresh(double time);

        // stub for com protocol
        void send(double timeStamp, double val);

    private:
        std::vector<std::string> buffer_;
};

#endif /* SERVER_H_ */
