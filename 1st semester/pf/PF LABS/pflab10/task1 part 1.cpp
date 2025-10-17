#include <iostream>
#include <array>
using namespace std;


array<float, 12> rearrangearray(array<float, 12> arr) {
    array<float, 12> a;
    float pivot = arr[11];
    int j = 0, k = 11;


    for (int i = 0; i < 11; i++) 
	{
        if (arr[i] < pivot)
		 {
            a[j] = arr[i];
            j++;
		}
		 else
		  {
           a[k] = arr[i];
           k--;
    }
    }
    a[j] = pivot; 
    return a;
}

int main() {
    const int size = 12;
    array<float, size> arr;


    for (int i = 0; i < size; i++) {
        cout << "Enter num: ";
        cin >> arr[i];
    }

 
    array<float, size> correct = rearrangearray(arr);


    cout << "Rearranged array: ";
    for (int i = 0; i < size; i++) {
        cout << correct[i] << " ";
    }
    cout << endl;

    return 0;
}
