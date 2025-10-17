#ifndef Process_H
#define Process_H

#include <iostream>
using namespace std;

class Process
{
    private:
        int processId;
        string processName;
        int executionTime;
    public:
        Process(){
            processId = 0;
            processName = "";
            executionTime = 0;
        }
        Process(int id , string name , int time){
            processId = id;
            processName = name;
            executionTime = time;
        }

        int getId(){
            return processId;
        }

        string getName(){
            return processName;
        }

        int getExecutionTime(){
            return executionTime;
        }

        void setExecutionTime(int t){
            executionTime = t;
        }
};

#endif
