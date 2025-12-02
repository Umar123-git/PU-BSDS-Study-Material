#include<iostream>
#include<array>
#include<cmath>
using namespace std;



template<typename T>
class Tree
{
private:
    int height;
    T *data;
    bool *status;
public:
    Tree(int h){
        height=h;
        data = new T[pow(2,h)-1];
        status = new bool[pow(2,h)-1];

        for(int i=0 ; i<pow(2,h)-1 ; i++){
            status[i]=false;
        }
    }

    ~Tree()
    {
        delete [] data;
        delete [] status;
        height=0;
    }

    void setleft(T p, T v){
        for(int i=0 ; i<pow(2,height)-1 ; i++)
        {
            if(data[i]==p && (2*i)+1 < pow(2,height)-1){
                data[(2*i)+1]=v;
                status[(2*i)+1]=true;
            }
        }
    }

    void setright(T p, T v){
        for(int i=0 ; i<pow(2,height)-1 ; i++)
        {
            if(data[i]==p && (2*i)+2 <= pow(2,height)-1){
                data[(2*i)+2]=v;
                status[(2*i)+2]=true;
            }
        }
    }

    T getparent(T p){
        for(int i=0 ; i<pow(2,height)-1 ; i++){
            if(status[i] && 
                (( (2*i)+1 < pow(2,height)-1 && status[(2*i)+1] && data[(2*i)+1]==p ) || 
                ( (2*i)+2 < pow(2,height)-1 && status[(2*i)+2] && data[(2*i)+2]==p ))) return data[i];
        }
        throw "\nNo such parent exist";
    }
    
};

