#include <iostream>
#include <array>

using namespace std;

array<int,50> aget(int N);
void ashow(array<int,50> a, int N);

int main()
{
    int size;
    cout << "Enter the size of data (count of values not more then 50): ";
    cin >> size;
    cout << "Enter data (values) one by one" << endl;

	array<int,50> v;
    v = aget(size);
	
    cout << "You entered values: " << endl;
    ashow(v,size);
	return 0;
}

array<int,50> aget(int N)
{
    array<int,50> ar;
    int j = 0;
    while(j < N)
    {
        cin >> ar[j];
        j = j + 1;
    }
    return ar;
}

void ashow(array<int,50> data, int N)
{
    int j = 0;
    while(j < N)
    {
        cout << data[j] << endl;
        j = j + 1;
    }
}
