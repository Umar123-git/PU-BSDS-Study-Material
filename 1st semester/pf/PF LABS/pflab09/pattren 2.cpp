#include <iostream>
using namespace std;

void pattern2(int n)
 {
 	int i=1;
     while (i <= n)
	 {
        for (int j = 1; j <= i; ++j) 
		{
            cout << "*";
        }
        cout << endl;
        i++;
    }
}

int main() {
    pattern2(6);
    return 0;
}




	
  