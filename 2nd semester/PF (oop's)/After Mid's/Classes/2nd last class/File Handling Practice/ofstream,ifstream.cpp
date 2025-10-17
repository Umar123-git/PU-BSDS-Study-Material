#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
int main() 
{
string numfile = "numbers.txt";
ofstream ofile;
ofile.open(numfile.c_str() , ios::app);
if (!ofile)
{
    cout << "Error opening file for writing." << endl;
    return 1;
}
string st ="This is a test file.\n";
int j = 0;
while(j<10)
{
ofile << j << " " << st ;
j = j + 1;
}
//ofile << "End of file.\n";

ofile.close();




    ifstream ifile(numfile.c_str());
    if (!ifile) {
        cout << "Error opening file for reading." << endl;
        return 1;
    }
    string line;
    while(getline(ifile,line))
    {
        cout << line << endl;
    }
    //getline(ifile,line);
    //cout << line << endl;
    ifile.close();
    return 0;
}
