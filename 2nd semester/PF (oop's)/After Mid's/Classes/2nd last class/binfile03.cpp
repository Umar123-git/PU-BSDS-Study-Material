#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct tension
{
    int i;
    char c;
};

int main() 
{
    int ia[2] = {2082322, -1};
    double da[3] = {0.02, 1.0/4.0, 7618118};
    tension tv = {20, '\t'};
    char ec = 26;
    char ca[] = "rabbit no. 1";
    
	ofstream f("bin02.bin", ios::binary);
    f.write(reinterpret_cast<char *>(ia), sizeof(ia));
    f.write(reinterpret_cast<char *>(da), sizeof(da));
    f.write(reinterpret_cast<char *>(&ec), 1);
    f.write(reinterpret_cast<char *>(&tv), sizeof(tv));
    f.write(reinterpret_cast<char *>(ca), sizeof(ca));
	f.close();
    
   return 0;
}