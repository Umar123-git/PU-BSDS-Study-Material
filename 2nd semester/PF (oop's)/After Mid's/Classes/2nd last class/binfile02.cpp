#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef short number; // short int unsigned char

int main() 
{
	ifstream iif("bin01.bin", ios::binary);
    
    number a[10];
    iif.read(reinterpret_cast<char *>(a), sizeof(number)*10);
	iif.close();
    
    for (int i=0; i<10; i+=1)
    {
        cout << a[i] << endl;
    }

   return 0;
}