#include<iostream>
#include<array>
using namespace std;


void printND(int val)
{
    /*if(val == 0)return ;
    if(val == 1)cout<<"I1";return ;
*/
    for(int i=1 ; i<=val ; i++)
    {
        cout<<"I"<<i;
        for(int j=i+1 ; j<=val ; j++)
        {
            cout<<"U"<<j;
        }
        if(i==val)break;
        cout<<"+";
    }

}


int main()
{

    printND(5);



    return 0;
} 