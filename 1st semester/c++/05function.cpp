#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float avrg(float n1, float n2, float n3, float n4);
int main();

int main()
{
	float w;
	float x;
	float y;
	float z;
    
    cout << "Enter 4 numbers in a line seperate by space: "; 
	cin >> w >> x >> y >> z;
    
    cout << "The average of above numbers is " << avrg(w, x, y, z) << endl;

	return 0;
}

float avrg(float n1, float n2, float n3, float n4)
{
    float sum;
    sum = n1 + n2 + n3 + n4;
    return sum / 4.0;
}
