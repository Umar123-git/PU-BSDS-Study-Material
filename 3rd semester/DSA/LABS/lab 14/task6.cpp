#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;


class Graph{
    private:
        int maxsize;
        int currsize;
        list<int> *l;
        bool* vis;

        
        void DFS (int v){
            queue<int> q;
            q.push(v);
            vis[v] = true;

            while(q.size()>0){
                int u = q.front();
                q.pop();

                cout<< u << " ";

                for(int v : l[u]){
                    if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }

        }

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
            //currsize--;
            return t;
        }

        void clear(){
            for(int i=0 ; i<currsize ; i++){
                l[i].clear();
            }
            //currsize=0;
        }

        int degree(int v){
            if(isempty()){
                return -1;
            }
            return l[v].size();
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

        void helperDFS(){
            if(this->isempty()){
                return;
            }
            int m = INT_MAX;
                for(int i=0 ; i<currsize ; i++){
                    if(!vis[i]){
                        if(i<m){
                            m=i;
                        }
                    }
                }
                if(m!=INT_MAX){
                    DFS(m);
                }

        }

        void DFS (){
            if(!this->isempty()){
                vis = new bool[currsize];
                for(int i=0 ; i<currsize ; i++){
                    vis[i] = false;
                }
                //DFS(0);
                //helperDFS();

                for(int i=0 ; i<currsize ; i++){
                    vis[i]==false;
                    helperDFS();
                }
            }
        }

        Graph(const Graph &g){
            maxsize = g.maxsize;
            currsize = g.currsize;
            l = new list<int> [maxsize];
            for(int i=0 ; i<currsize ; i++){
                l[i] = g.l[i];
            }
        }

        void display(){
            for(int i=0 ; i<currsize ; i++){
                cout<< i <<" : ";
                //if(l[i].empty()){
                //    cout<<endl;
                //    continue;
                //}
                for(int n : l[i]){
                    cout<< n << " ";
                }
                cout<<endl;
            }

            cout<<endl;
        }
};


int main()
{

    cout<<"----------------Task 1----------------\n";
    Graph g(5,5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    
    g.display();


    g.removeEdge(2,4);
    g.display();

    cout<<"\n----------------Task 2----------------\n";
    cout<<g.isempty()<<endl;
    cout<<g.isfull()<<endl;
    cout<<g.degree(2)<<endl;
    //g.clear();
    g.display();


    cout<<"\n----------------Task 3----------------\n";
    cout<<"\n----------------Task 4----------------\n";
    Graph g2(g);
    g2.display();

    cout<<"\n----------------Task 5----------------\n";
    g.DFS();


    return 0;
}