#include<iostream>
#include<string>
using namespace std;

string check_difference(int a, int b, int c)
{
    if(a-b>c)
    {
        return "Waoo";
    }
    else
    {
        return "Ohhh";
    }
}

int main()
{
    int a, b, c;
    cout << "enter the values of a, b, c :";
    cin >> a >> b >> c;
    cout<<check_difference(a , b , c);
    return 0;
}
