#include<iostream>
#include<fstream>
using namespace std;


int main()
{
    ifstream in("data.txt");
    ofstream out("data2.txt");
    string s;
    
    while(getline(in,s))
    {
        out<<s<<endl;
        
    }

out.close();
in.close();

    return 0;
}