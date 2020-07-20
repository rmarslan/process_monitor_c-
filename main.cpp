#include <iostream>
#include <vector>
#include "ProcessParser.h"
#include <string>

int main() {
	std::vector<std::string> res = ProcessParser::getPidList();
	for(std::string pid : res) {
		ProcessParser::getVmSize(pid);
	}
	return 0;
}
