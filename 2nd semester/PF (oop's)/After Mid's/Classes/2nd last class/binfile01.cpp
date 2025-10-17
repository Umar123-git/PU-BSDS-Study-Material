#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() 
{
	ofstream oof("bin01.bin", ios::binary);
    
    for (short i=101; i<=110; i+=1)
    {
        oof.write(reinterpret_cast<char *>(&i), sizeof(short));
    }

	oof.close();
	
	
   return 0;
}