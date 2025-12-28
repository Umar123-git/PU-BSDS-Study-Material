#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


class Graph{
    int maxsize;
    int currsize;
    list<int> *l;

    public:
        Graph(int a=0, int b=0){
            maxsize=a;
            currsize=b;
            l = new list<int> [maxsize];
        }

        ~Graph(){
            delete [] l;
            maxsize=0;
            currsize=0;
        }

        bool addVertex(int& v){
            if(!isfull()){
                v=currsize;
                currsize++;
                return true;
            }
            return false;
        }

        bool removeEdge(int u, int v){
            if(isempty()){
                return 0;
            }
            bool t = false;
            for(int i : l[u]){
                if(i==v){
                    l[u].remove(i);
                    t=true;
                    break;
                }
            }
            for(int i : l[v]){
                if(i==u){
                    l[v].remove(i);
                    t=true;
                    break;
                }
            }
            currsize--;
            return t;
        }

        bool isfull(){
            return currsize==maxsize;
        }

        bool isempty(){
            return currsize==0;
        }

        void addEdge(int u, int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }


        void display(){
            for(int i=0 ; i<currsize ; i++){
                cout<< i <<" : ";
                for(int n : l[i]){
                    cout<< n << " ";
                }
                cout<<endl;
            }
        }
};

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    
    g.display();
    return 0;
}