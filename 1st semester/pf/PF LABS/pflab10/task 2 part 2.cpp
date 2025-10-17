#include <iostream>
#include <array>
using namespace std;

void mergeSortedParts(array<float, 20>& arr, int mid)
 {
    int i = 0;          
    int j = mid+1;     

    while (i <= mid && j < 20) 
	{
        if (arr[i] <= arr[j])
		 {
            i++;
        } 
		else
		 {
        float t = arr[j];
        for (int k = j; k > i; k--) {
        arr[k] = arr[k - 1]; 
        }
        arr[i] = t; 
        i++;
        mid++;
        j++;
    }
}
}
int main()
 {
    array<float, 20> arr = {7, 12, 25, 45, 82, 97, 3, 34, 38, 40, 49, 52, 65, 83, 91};

    int mid = 5;

    mergeSortedParts(arr, mid);

    cout << "Sorted Array: ";
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
