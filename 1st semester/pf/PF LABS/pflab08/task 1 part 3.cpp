#include<iostream>
#include<cmath>
#include<array>
using namespace std;

int maxvalue(array<int,100> arr ,int n)
{

	

	int max=0;
	int i=0;
	int j=0;
	while(i<n)
	{
		if(arr[i]!=0)
		{
			max=arr[i];
		}
		i++;
	}

	cout<<"loction of max value is :"<<endl;
	return max;
}





int main()
{
	array<int,100>arr={ 9 , 7 , 2 , 9 , 3 , 77 , 8 , 3 , 8 , 55};
	int n = 10;

	
    int j=maxvalue(arr,n);
	cout<<j<<endl;
	
	return 0;
}