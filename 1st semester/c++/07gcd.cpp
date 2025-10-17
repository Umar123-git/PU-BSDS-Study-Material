#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int gcd(int n1, int n2);

int main()
{
    gcd(56, 72);
	return 0;
}

int gcd(int n1, int n2)
{
    int t;
    while(n1 != 0)
    {
        t = n2 % n1;
        n2 = n1;
        n1 = t;
    }
    cout << n2 << endl;
    
	return 0;
}
