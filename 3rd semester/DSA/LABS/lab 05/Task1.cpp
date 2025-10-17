#include<iostream>
using namespace std;



int dec2oct(int n)
{
    if(n<8)return n;

    return (dec2oct(n/8)*10)+(n%8);

}

int main()
{
    int n=69;
    cout<<"Octal equivalent of "<<n<<" is: "<<dec2oct(n)<<endl;
    //dec2oct(n);
    n=389;
    //dec2oct(n);
    cout<<"Octal equivalent of "<<n<<" is: "<<dec2oct(n)<<endl;

    return 0;
}