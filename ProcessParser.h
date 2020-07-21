#ifndef PROCESS_PARSER_H
#define PROCESS_PARSER_H

#include <vector>
#include <string>
#include <dirent.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sstream> //std::isstringstream()
#include <iterator> //std::isstream_iterator
#include <fstream>
#include <stdio.h>
#include "utill.h"
#include "Path.h"

class ProcessParser {
    public: 
        static std::vector<std::string> getPidList();
        static std::string getVmSize(std::string pid);
        static std::string getProcUser(std::string pid);
};

std::vector<std::string> ProcessParser::getPidList() {
    std::vector<std::string> container;
	DIR *dir;
	dirent *dirp;
	dir = opendir("/proc");
	if(dir == NULL) {
		std::cout<<"Error: failed to open the folder"<<std::endl;
		exit(1);
	} 

	while((dirp = readdir(dir)) != NULL) {
		if(dirp->d_type != DT_DIR) continue;
		if(std::all_of(dirp->d_name, dirp->d_name + std::strlen(dirp->d_name), [](char c) { return std::isdigit(c);})) {
			container.push_back(dirp->d_name);
		}
	}

    return container;
}

std::string ProcessParser::getVmSize(std::string pid) {
    std::string line;
    std::string name = "VmData";
    std::string value;
    int result;
    // open stream for a specific file
    std::ifstream stream = Util::getStream( (Path::basePath() + pid + Path::statusPath()) );

    while (std::getline(stream, line)) {
        if (line.compare(0, name.size(), name) == 0) {
            std::istringstream buf(line); // convert file stream to string stream
            
            // std::string str;
            // float f;
            // buf >> str;
            // buf >> f;
            // std::cout<<str<<": "<<f<<std::endl;
            
            std::istream_iterator<std::string> begin(buf), end;
            std::vector<std::string> values(begin, end);

            // conversion kB -> GB
            // result = ( stof(values[1]) / float(1024*1024) );
            result = stof(values[1]);
            break;
        }
    }
    return std::to_string(result);
}

/* Retrieve the process user thru UID*/
std::string ProcessParser::getProcUser(std::string pid) {
    std::string line;

    std::string name = "Uid";
    std::string result = "";
    // open stream for a specific line
    std::ifstream stream = Util::getStream( ( Path::basePath() + pid + Path::statusPath() ) );

    // Getting UID for user
    while ( std::getline(stream, line) ) {
        if ( line.compare(0, name.size(), name) == 0 ) {
            std::istringstream buf(line);
            std::istream_iterator<std::string> begin(buf), end;
            std::vector<std::string> values(begin, end);
            result = values[1];
            break;
        }
    }
    stream = Util::getStream("/etc/passwd");
    name = "x:" + result;

    // Search for name of the user with selected UID
    while ( std::getline(stream, line) ) {
        if ( line.find(name) != std::string::npos ) {
            result = line.substr( 0, line.find(":") );
            return result;
        }
    }

    return "";
}

#endif