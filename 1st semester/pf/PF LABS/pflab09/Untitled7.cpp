#include <iostream>
using namespace std;

void pattern1(int n)
{
	int i=1,j=1;
	while(i<=6)
	{
		while(j<=6)
		{
			cout<<j<<endl;
			j++;
		}
	cout<<endl;
		i++;
	}

}
int main()
{
	pattern1(6);
	return 0;
}