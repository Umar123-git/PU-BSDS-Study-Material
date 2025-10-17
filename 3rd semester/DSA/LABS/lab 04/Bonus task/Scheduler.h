#ifndef Scheduler_H
#define Scheduler_H
#include "process.h"
#include "Queue.h"

#include <iostream>
using namespace std;

class Scheduler
{
    private:
        Queue<Process> q;
        int timeQuantum;
    public:
        Scheduler(Process arr[], int len, int tq){
            if(len == 0)throw ("\ninvalid array");
            q = Queue<Process>(4);
            for(int i=0 ; i<len ; i++){
                q.enqueue(arr[i]);
            }

            timeQuantum = tq;
        }

        void assignProcessor(){
            if(q.isEmpty())throw ("\nthere is no task assigned to cpu");

            while(!q.isEmpty())
            {
                //auto [id,pro,t] = q.dequeue();
                Process p =q.dequeue();
                int id = p.getId();
                string pro = p.getName();
                int t = p.getExecutionTime();
                cout<<"\nEcecuting process "<<pro<<" for "<<timeQuantum<<" units";
                t-=timeQuantum;
                if(t>0){
                    q.enqueue({id,pro,t});
                }
            }
        }
};

#endif