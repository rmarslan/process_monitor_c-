#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include "ProcessParser.h"

class Process
{
private:
    std::string pid_;
    std::string user_;
    std::string mem_;
    std::string cmdCommand_;
    float memPer_;

public:
    Process(std::string pid)
    {
        this->pid_ = pid;
        this->user_ = ProcessParser::getProcUser(pid);
        this->mem_ = ProcessParser::getVmSize(pid);
        this->cmdCommand_ = ProcessParser::getCmd(pid);
        this->memPer_ = ProcessParser::getProcessPercent(pid);
    }

    // getters
    std::string getPid() const;
    std::string getUser() const;
    int getMem() const;
    std::string getCmd() const;
    float getMemPer() const;
};

// definitions of getters
std::string Process::getPid() const
{
    return this->pid_;
}

std::string Process::getUser() const
{
    return this->user_;
}

int Process::getMem() const
{
    return std::stod(mem_); // A c++11 feature;
}

std::string Process::getCmd() const
{
    return this->cmdCommand_;
}

float Process::getMemPer() const
{
    return this->memPer_;
}

#endif