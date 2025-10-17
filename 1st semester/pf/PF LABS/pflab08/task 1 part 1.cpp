#include<iostream>
#include<cmath>
#include<array>
using namespace std;

int maxvalue(array<int,100> arr ,int n)
{

	

	int max=0;
	int i=0;
	while(i<n)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
		i++;
	}
	
	return max;
}





int main()
{
	array<int,100>arr={5 , 7 , 2 , 9 , 3 , 8 , 3 , 8 , 55};
	int n = 10;

	
    int j=maxvalue(arr,n);
	cout<<j<<endl;
	
	return 0;
}