#include <iostream>
#include <cmath>
using namespace std;

float average(float a, float b, float c)
{
	float avg=(a+b+c)/3;
	
	return avg;
}

int main()
{
    int a, b, c,avg;
    cout << "Enter three values: ";
    cin >> a >> b >> c;
    cout << "Their average is: " << average(a,b,c) << endl;
    return 0;
}
