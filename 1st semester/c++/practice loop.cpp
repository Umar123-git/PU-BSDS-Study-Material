#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int min1=99999999999999,min2,i=1;
    int num[10];
    while(i<=10)
    {
    	cin>>num[i];
    	if(num[0]<num[1])
    	{
    		min1=num[0];
    		min2=num[1];
		}
    	i++;
	}
	

		cout<<min1<<min2;
	return 0;
}