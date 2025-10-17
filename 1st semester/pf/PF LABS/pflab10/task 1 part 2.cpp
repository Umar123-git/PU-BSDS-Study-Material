#include <iostream>
#include <array>
using namespace std;

void rearrangearray(array<float, 12> arr) {
    float pivot = arr[11]; 
    int low = 0, high = 10; 

    while (low <= high)
	 {
        
       if (arr[low] < pivot)
	    {
            low++;
    }
        
        else if (arr[high] >= pivot)
		 {
            high--;
       }
       
        else
		 {
            float temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }


    float temp = arr[low];
    arr[low] = arr[11];
    arr[11] = temp;
}

int main() {
    const int size = 12;
    array<float, size> arr;

    for (int i = 0; i < size; i++) {
        cout << "Enter num: ";
        cin >> arr[i];
    }

    rearrangearray(arr);

    cout << "Rearranged array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
