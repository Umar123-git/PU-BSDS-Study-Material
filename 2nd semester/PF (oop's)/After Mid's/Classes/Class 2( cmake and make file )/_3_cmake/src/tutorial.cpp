#include <iostream>
#include <string>

#include "include/other.h"

using namespace std;

int main(int argc, char *argv[])
{
//    int main2(); // a declaration
    
    cout << stod(argv[1]) << endl;

    string q;
    getline(cin, q);
    //char q[100];
    //cin.getline(q, 100);
    cout << stod(q) << endl;
    
    return main2()*9;
}
