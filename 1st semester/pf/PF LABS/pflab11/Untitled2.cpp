#include <iostream>
#include <array>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void printArrayWithRowTotals(const array<array<int, COLS>, ROWS>& arr) {
    for (int i = 0; i < ROWS; ++i) {
        int rowTotal = 0;
        for (int j = 0; j < COLS; ++j) {
            cout << arr[i][j] << " ";
            rowTotal += arr[i][j];
        }
        cout << "| " << rowTotal << endl;
    }
}

int main() {
    array<array<int, COLS>, ROWS> arr = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    printArrayWithRowTotals(arr);
    return 0;
}
