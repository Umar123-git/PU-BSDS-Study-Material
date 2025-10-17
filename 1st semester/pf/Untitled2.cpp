#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    double numbers[size], sum = 0.0, average;
    int i = 0;

    cout << "Enter 10 numbers:" << endl;

    while (i < size) {
        cin >> numbers[i];
        sum += numbers[i];
        i++;
    }

    average = sum / size;

    cout << "The average is: " << average << endl;
    cout << "Numbers above the average are: ";

    i = 0; // Reset index for second while loop
    while (i < size) {
        if (numbers[i] > average) {
            cout << numbers[i] << " ";
        }
        i++;
    }
    cout << endl;

    return 0;
}