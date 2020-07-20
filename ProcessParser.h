#ifndef PROCESS_PARSER_H
#define PROCESS_PARSER_H

#include <vector>
#include <string>
#include <dirent.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <fstream>
#include <stdio.h>
#include "utill.h"
#include "Path.h"

class ProcessParser {
    public: 
        static std::vector<std::string> getPidList();
        static std::string getVmMemory(std::string pid);
        static std::string ProcessParser::getVmSize(std::string pid);
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

    // declare search attributes for file
    std::string name = "VmData";
    std::string value;
    float result;

    // open stream for a specific file
    std::ifstream stream = Util::getStream( (Path::basePath() + pid + Path::statusPath()) );

    while (std::getline(stream, line)) { // read the data by lines
        // searching line by line
        if (line.compare(0, name.size(), name) == 0) {
            // slicing string line on ws for values using sstream
            // Note: 1. it is using buf to collect each line;
            //       2. and parse it into begin and end
            //       3. finally it processes into a vector of string
            // Example:
            //       1. try "cat /proc/16559/"
            //       2. one can get:
            //              "...
            //               VmData: 1131692 kB
            //               ..."
            //       3. Here, "1131692" is the values[1]
            std::istringstream buf(line);
            std::istream_iterator<std::string> begin(buf), end;
            std::vector<std::string> values(begin, end);

            // conversion kB -> GB
            result = ( stof(values[1]) / float(1024*1024) );
            break;
        }
    }

    return std::to_string(result);
}

#endif