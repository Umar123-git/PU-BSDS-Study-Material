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
void pattern3(int n)
 {
	
    for (int i = n; i >= 1; --i)
	 {
        for (int j = 1; j <= i; ++j) 
		{
            cout << j;
        }
        cout << endl;
    }
}


int main()
 {
    pattern1(3);
    cout<<".."<<endl;
    pattern3(3);
    return 0;
}





