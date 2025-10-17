#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


    int countWays(int numStairs, int a, int b, int ans){
        if(numStairs==2){
            return ans;
        }
        ans=a+b;
        swap(a,b);
        b=ans;
        return countWays(numStairs-1,a,b,ans);
    }


int main()
{
    cout<<countWays(10,1,2,0);

    return 0;
}