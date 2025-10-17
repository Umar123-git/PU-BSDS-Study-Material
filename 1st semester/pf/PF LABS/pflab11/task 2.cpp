#include <iostream>
#include <array>
#include<cmath>
using namespace std;

array<array<int,3>,4> aget();
void ashow(array<array<int,3>,4> a);


int main()
{
	array<array<int,3>,4> v;
    v = aget();
	
    cout << "You entered values: " << endl;
    ashow(v);
	return 0;
}

array<array<int,3>,4> aget()
{
    array<array<int,3>,4> ar;
    int j = 0,sum=0;
    while(j < 3)
    {
        int k = 0;
        while(k < 3)
        {
            cin >> ar[j][k];
            
            k = k + 1;
        }
        j = j + 1;
    }
    return ar;
}

void ashow(array<array<int,3>,4> data)
 {
    for (int j = 0; j < 3; ++j) {
        int sum = 0;
        for (int k = 0; k < 3; ++k) {
            cout << data[j][k] << " ";
            sum += data[j][k];
        }
        cout << "sum " << sum << endl;
    }
}
