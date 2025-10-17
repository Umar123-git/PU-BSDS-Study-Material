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
    int ia[2];
    double da[3];
    tension tv;
    char ec;
    char ca[12];
    
	ifstream f("bin02.bin", ios::binary);
    f.read(reinterpret_cast<char *>(ia), sizeof(ia));
    f.read(reinterpret_cast<char *>(da), sizeof(da));
    f.read(reinterpret_cast<char *>(&ec), 1);
    f.read(reinterpret_cast<char *>(&tv), sizeof(tv));
    f.read(reinterpret_cast<char *>(ca), sizeof(ca));
	f.close();
    
    cout << ia[0] << "~~~" << ia[1] << endl;
    cout << da[0] << "~~~" << da[1] << "~~~" << da[2] << endl;
    cout << static_cast<int>(ec) << endl;
    cout << tv.i << "~~~" << static_cast<int>(tv.c) << endl;
    cout << ca << "~~~" << endl;
    
    return 0;
}