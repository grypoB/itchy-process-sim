#include "Server.h"
#include <iostream>


Server::Server() : buffer_(0,0) {}

void Server::refresh(double time) {
    std::cout << time << "  Server output" << std::endl;
    for (unsigned int i=0 ; i<buffer_.size() ; i++) {
        std::cout << buffer_.at(i) << std::endl;
    }
    buffer_.clear();
}

void Server::send(double timeStamp, double val) {
    // TODO redo this function
    buffer_.push_back(std::to_string(timeStamp) + " " + std::to_string(val));
}
