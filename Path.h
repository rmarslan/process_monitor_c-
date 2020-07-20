#ifndef PATH_H
#define PATH_H

#include <string>

class Path{
    public:
        static std::string basePath(){ return "/proc/"; }
        static std::string statusPath(){ return "/status"; }
        static std::string statPath(){ return "stat"; }
};

#endif