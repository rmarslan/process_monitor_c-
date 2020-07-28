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
    float usedSysMem;
    float usedSysMemPercent;

public:
    SysInfo()
    {
        this->OSName = ProcessParser::getOSName();
        this->kernelVersion = ProcessParser::getSysKernelVersion();
        this->totalSysMem = ProcessParser::getTotalSysMem();
        this->availableSysMemory = ProcessParser::getAvailableSysMem();
        this->usedSysMem = ProcessParser::getUsedSysMemory();
        this->usedSysMemPercent = ProcessParser::getSysMemPercent();
    }
    std::string getOSName();
    std::string getKernelVersion();
    float getTotalSysMem();
    float getAvailableSysMem();
    float getUsedSysMem();
    float getSysMemPercent();
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

float SysInfo::getUsedSysMem()
{
    float memInGB = (this->usedSysMem / (1024 * 1024));
    return memInGB;
}

float SysInfo::getSysMemPercent()
{
    return this->usedSysMemPercent;
};