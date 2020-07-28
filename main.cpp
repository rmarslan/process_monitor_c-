#include <iostream>
#include <vector>
#include <string>
#include "Process.h"
#include "ProcessContainer.h"
#include "SysInfo.h"

void printSysInfo(SysInfo sys)
{
	std::cout << "OS: " << sys.getOSName() << std::endl;
}

int main()
{
	SysInfo sys;
	ProcessContainer processContainer;
	printSysInfo(sys);
	processContainer.printList();
}
