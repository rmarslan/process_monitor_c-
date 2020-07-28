#include <iostream>
#include <string>
#include "ProcessParser.h"

class SysInfo
{
private:
    std::string OSName;
    std::string kernelVersion;

public:
    SysInfo()
    {
        this->OSName = ProcessParser::getOSName();
        this->kernelVersion = ProcessParser::getSysKernelVersion();
    }
    std::string getOSName();
    std::string getKernelVersion();
};

std::string SysInfo::getOSName()
{
    return this->OSName;
}

std::string SysInfo::getKernelVersion()
{
    return this->kernelVersion;
}