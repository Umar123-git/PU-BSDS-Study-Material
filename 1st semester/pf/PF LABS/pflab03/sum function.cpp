#include <iostream>
#include <cmath>
using namespace std;

int sum(int n)

{
    int s;
    s=n*(n+1)/2;
    return s;	
}
int main()

{

	int s,n;
	cout<<"number";
	cin>>n;
	s=sum(n);
	cout<<s<<endl;
	return 0;
	
	
	
	
}