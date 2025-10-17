#include <iostream>
#include <cstdlib> 
#include <ctime>  
using namespace std;

int main() {
    const int size = 25;
    int arr[size];
    int i = 0;


    srand(time(0));
    while (i < size) {
        arr[i] = rand() % 100;
        i++;
    }

 
    i = 0;
    
    cout << "Consecutive pairs in order are:" << endl;
    while (i < size - 1) {
        if (arr[i] <= arr[i + 1]) {
            cout << arr[i] << " and " << arr[i + 1] << endl;
        }
        i++;
    }

    return 0;
}
