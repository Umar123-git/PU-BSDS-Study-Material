#include <iostream>
using namespace std;

void pattern3(int n)
 {
	
    for (int i = n; i >= 1; --i)
	 {
        for (int j = 1; j <= i; ++j) 
		{
            cout << "X";
        }
        cout << endl;
    }
}

int main() {
    pattern3(6);
    return 0;
}
