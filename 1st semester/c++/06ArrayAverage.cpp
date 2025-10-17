#include <iostream>
#include <array> // For std::array
using namespace std;

int main() {
    const int size = 10;
    array<int, size> numbers;
    int i = 0;
    double sum = 0;

    cout << "Enter 10 numbers:" << endl;

    // Use a while loop to get user input
    while (i < size) {
        cin >> numbers[i];
        sum += numbers[i];
        i++;
    }

    // Calculate the average
    double average = sum / size;

    // Output the result
    cout << "The average is: " << average << endl;

    return 0;
}
