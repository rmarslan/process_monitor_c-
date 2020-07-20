#include <iostream>
#include <vector>
#include "ProcessParser.h"
#include <string>

int main() {
	std::vector<std::string> res = ProcessParser::getPidList();
	for(std::string pid : res) {
		std::cout<<pid<<std::endl;
	}
	return 0;
}
