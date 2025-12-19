#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;


class Graph{
    private:
        int maxsize;
        int currsize;
        // list<int>* l
        int** l;
        bool* vis;

        
        void DFS (int v){
            queue<int> q;
            q.push(v);
            vis[v] = true;

            while(q.size()>0){
                int u = q.front();
                q.pop();

                cout<< u << " ";

                // for(int v : l[u]){
                //     if(!vis[v]){
                //         vis[v]=true;
                //         q.push(v);
                //     }
                // }
                for(int v = 0; v < currsize; ++v){
                    if(l[u][v] && !vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }

        }

    public:
        Graph(int a=0, int b=0){
            maxsize=a;
            currsize=b;
            // l = new list<int> [maxsize];
            l = new int*[maxsize];
            for(int i = 0; i < maxsize; ++i){
                l[i] = new int[maxsize];
                for(int j = 0; j < maxsize; ++j){
                    l[i][j] = 0;
                }
            }
        }

        ~Graph(){
            for(int i = 0; i < maxsize; ++i){
                delete [] l[i];
            }

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
            if(u < currsize && v < currsize && l[u][v]){
                l[u][v] = 0;
                l[v][u] = 0;
                t = true;
            }
            //currsize--;
            return t;
        }

        void clear(){
            for(int i=0 ; i<currsize ; i++){
                // l[i].clear();
                for(int j = 0; j < currsize; ++j){
                    l[i][j] = 0;
                }
            }
            //currsize=0;
        }

        int degree(int v){
            if(isempty()){
                return -1;
            }
            int d = 0;
            for(int j = 0; j < currsize; ++j){
                if(l[v][j]) ++d;
            }
            return d;
        }

        bool isfull(){

            return currsize==maxsize;
        }

        bool isempty(){
            return currsize==0;
        }

        void addEdge(int u, int v){
            // l[u].push_back(v);
            // l[v].push_back(u);
            if(u < currsize && v < currsize){
                l[u][v] = 1;
                l[v][u] = 1;
            }
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
            // l = new list<int> [maxsize];
            l = new int*[maxsize];
            for(int i = 0; i < maxsize; ++i){
                l[i] = new int[maxsize];
                for(int j = 0; j < maxsize; ++j){
                    l[i][j] = g.l[i][j];
                }
            }
        }

        void display(){
            for(int i=0 ; i<currsize ; i++){
                cout<< i <<" : ";
                // for(int n : l[i]){
                //     cout<< n << " ";
                // }
                for(int j = 0; j < currsize; ++j){
                    if(l[i][j]){
                        cout << j << " ";
                    }
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