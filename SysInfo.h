#include <iostream>
#include <string>
#include "ProcessParser.h"

class SysInfo
{
private:
    std::string OSName;
    std::string kernelVersion;
    float totalSysMem;
    float availableSysMemory;

public:
    SysInfo()
    {
        this->OSName = ProcessParser::getOSName();
        this->kernelVersion = ProcessParser::getSysKernelVersion();
        this->totalSysMem = ProcessParser::getTotalSysMem();
        this->availableSysMemory = ProcessParser::getAvailableSysMem();
    }
    std::string getOSName();
    std::string getKernelVersion();
    float getTotalSysMem();
    float getAvailableSysMem();
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

float SysInfo::getAvailableSysMem()
{
    float memInGB = (this->availableSysMemory / (1024 * 1024));
    return memInGB;
}