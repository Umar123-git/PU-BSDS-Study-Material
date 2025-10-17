#include <iostream>
#include <cmath>
using namespace std;

int squareroot(int r)
{
    int a;
	int i=1;
	while (a<=r)
	{
		a=i*i;
		i++;
    }
    return i-2;
}
	int main()
    {
		int n,r;
		cout<<"number square :";
		cin>>n;
		r=squareroot(n);
		cout<<r<<endl;
		return 0;
    }
