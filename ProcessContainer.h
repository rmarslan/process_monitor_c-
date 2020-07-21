#ifndef PROCESs_CONTAINER_H
#define PROCESS_CONTAINER_H

#include "Process.h"
#include "ProcessParser.h"
#include <vector>
#include <string>

class ProcessContainer{
  public:
    ProcessContainer(){
        this->refreshList();
    }
    void refreshList();
    void printList() const;
  private:
    std::vector<Process> _list;
};

void ProcessContainer::refreshList(){
    std::vector<std::string> pid_list = ProcessParser::getPidList();
    this->_list.clear();
    for(int i=0;i<pid_list.size();i++){
        Process proc(pid_list[i]);
        this->_list.push_back(proc);
    }
}

void ProcessContainer::printList() const {
    std::cout<<"PID\t\t\tUsername\t\t\tMemory\n----------------------------------------------------------------------------\n";
    for(const auto& process: this->_list) {
        const std::string pid = process.getPid();
        const std::string user = process.getUser();
        const float mem = process.getMem();

        std::cout<< pid << "\t\t\t" << user << "\t\t\t\t" << mem << " K" << std::endl;
    }
}

#endif