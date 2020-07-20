#ifndef UTIL_H
#define UTIL_H


#include <string>
#include <fstream>

class Util {
  public:
    static std::ifstream getStream(std::string path);
};
// Another version of Util::getStream
std::ifstream Util::getStream(std::string path) {
    std::ifstream stream(path);
    if (!stream) {
        throw std::runtime_error("Non-existing PID.");
    }
    return stream;
}

#endif