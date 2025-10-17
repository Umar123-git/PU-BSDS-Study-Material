#include <iostream>
#include <array>

using namespace std;

array<array<int,3>,3> aget();
void ashow(array<array<int,3>,3> a);

int main()
{
	array<array<int,3>,3> v;
    v = aget();
	
    cout << "You entered values: " << endl;
    ashow(v);
	return 0;
}

array<array<int,3>,3> aget()
{
    array<array<int,3>,3> ar;
    int j = 0;
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

void ashow(array<array<int,3>,3> data)
{
    int j = 0;
    while(j < 3)
    {
        int k = 0;
        while(k < 3)
        {
            cout << data[k][j] << "  ";
            k = k + 1;
        }
        cout << endl;
        j = j + 1;
    }
}
