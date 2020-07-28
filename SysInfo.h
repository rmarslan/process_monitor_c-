#include <iostream>
#include <string>
#include "ProcessParser.h"

class SysInfo
{
private:
    std::string OSName;
    std::string kernelVersion;
    float totalSysMem;

public:
    SysInfo()
    {
        this->OSName = ProcessParser::getOSName();
        this->kernelVersion = ProcessParser::getSysKernelVersion();
        this->totalSysMem = ProcessParser::getTotalSysMem();
    }
    std::string getOSName();
    std::string getKernelVersion();
    float getTotalSysMem();
};

std::string SysInfo::getOSName()
{
    return this->OSName;
}

std::string SysInfo::getKernelVersion()
{
    return this->kernelVersion;
}

float SysInfo::getTotalSysMem()
{
    float memoryInGB = (this->totalSysMem / (1024 * 1024));
    return memoryInGB;
}