#include <iostream>
#include <iomanip>
#include <string>
#include <exception> // For exception handling

using namespace std;

int main() {
    try {
        int x[4] = {32, 44, 12, -65};
        
        int j = 0;

        while(j < 4) {
            cout << setw(j*3) << hex << x[j] << endl;
            j += 1;
        }
        cout << j*222 << endl;
           
    } catch (const exception &e) {
        cerr << e.what() << endl; // Output exception message
    }

    return 0;
}
