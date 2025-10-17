#include <iostream>
using namespace std;

void pattern1(int n)
 {
 	int i=1,j=1;
 	
    while (i <= n)
	 {
        for (int j = 1; j <= i; ++j) 
		{
            cout << j;
        }
        cout << endl;
        i++;
    }
}

int main()
 {
    pattern1(6);
    return 0;
}
