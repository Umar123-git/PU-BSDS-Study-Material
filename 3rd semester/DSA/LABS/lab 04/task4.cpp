#include<iostream>
#include<vector>
#include"Queue.h"

struct pairs
{
    int i;
    int j;
};

class tickets
{
    private:
        Queue<pairs> q;
        int k;
    public:
        tickets()
        {

        }

        tickets(vector<int>& tickets, int j) {
            q = Queue<pairs>(tickets.size());
            k=j;
            for(int i=0 ; i<tickets.size() ; i++)
            {
                q.enqueue({tickets[i],i});
            }
        }


        int timeRequiredToBuy() {

            int time=0;
            while(!q.isEmpty()){
            auto [ticket,index]=q.front();
            q.dequeue();
            ticket--;
            time++;
            if(ticket>0){
                q.enqueue({ticket,index});
            }
            if(index == k && ticket == 0){
                return time;
            }
        }
        return time;
    }


};


int main()
{
    vector<int> a={3,5,3,7};
    int p=2;
    tickets t(a,p);
    cout<<t.timeRequiredToBuy();
    a={5,1,1,1};
    p=0;

    tickets t1(a,p);
    cout<<endl<<t1.timeRequiredToBuy();

}

