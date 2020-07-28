#ifndef PATH_H
#define PATH_H

#include <string>

class Path
{
public:
    static std::string basePath() { return "/proc/"; }
    static std::string statusPath() { return "/status"; }
    static std::string osPath() { return "os-release"; }
    static std::string etcPath() { return "/etc/"; }
    static std::string versionPath() { return "version"; }
    static std::string memInfoPath(){ return "meminfo"; }
};

#endif