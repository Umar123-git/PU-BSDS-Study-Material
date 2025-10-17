#include<iostream>
#include<cmath>
#include<array>
using namespace std;

int maxvalue(array<int,100> arr ,int n)
{

	


	int i=0;

	while(i<n-1)
	{
		if(arr[i]>arr[i+1])
		{
			cout<<"loction of disorder value is :"<<endl;
			return i+1;
		}
		i++;
	}


	return -1;
}





int main()
{
	array<int,100>arr={ 1,2,3,5,4,6,7,8,9};
	int n = 10;

	
    int j=maxvalue(arr,n);
	cout<<j<<endl;
	
	return 0;
}