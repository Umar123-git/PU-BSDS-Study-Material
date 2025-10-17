#include<iostream>
#include<array>

using namespace std;

int search(array<int,50>ar,int n, int v)
{
	int i=0;
	while (i<n)
   	{
		if(ar[i]=v)
		{
			return i;	}}
 
	return 3;
}
int main()
{
	int n=50,v;
	array<int,50>
	ar = {1,2,3,4,5,6,7,8,9,11,12,13,6,1,2,5,18,19,20,21,22,23,24,25,26,27,28,29,30};
	cout<<"enter integer to search :";
	cin>>v;
	int result = search(ar, n, v);
	if (result != -1) {
        cout << "the entered integer  " << v << " is at index "  << endl;
    } else {
        cout << v << " is not present in the array." << endl;
    }
return 0;
}