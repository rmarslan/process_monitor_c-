#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include "ProcessParser.h"

class Process {
  private:
    std::string pid_;
    std::string user_;
    std::string mem_;

  public:
    Process(std::string pid) {
        this->pid_ = pid;
        this->user_ = ProcessParser::getProcUser(pid);
        this->mem_ = ProcessParser::getVmSize(pid);
    }

    // getters
    std::string getPid()const;
    std::string getUser()const;
    int getMem()const;
};

// definitions of getters
std::string Process::getPid() const {
    return this->pid_;
}

std::string Process::getUser() const {
    return this->user_;
}


int Process::getMem() const {
    return std::stod(mem_); // A c++11 feature;
}

#endif