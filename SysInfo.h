#include <iostream>
#include <string>
#include "ProcessParser.h"

class SysInfo
{
private:
    std::string OSName;

public:
    SysInfo()
    {
        this->OSName = ProcessParser::getOSName();
    }
    std::string getOSName();
};

std::string SysInfo::getOSName()
{
    return this->OSName;
}