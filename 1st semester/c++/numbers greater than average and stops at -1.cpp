#include<iostream>
#include<array>
#include<cmath>
using namespace std;

int main()
{
float i=0.0,sum=0.0,avg,max=avg;
array<float,4>x={3.0,2.0,1.0,4.0};
    while(i<=4)
{
	sum=sum+x[i];
	i=i+1;
}
i=i-1;
avg=sum/i;
if(x[i]>max)
{
	cout<<x[i]<<endl;
}

    
	return 0;
}