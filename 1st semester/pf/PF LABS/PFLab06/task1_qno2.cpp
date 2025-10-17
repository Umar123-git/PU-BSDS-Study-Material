#include<iostream>
#include<cmath>
using namespace std;
int decimal(int);

int decimal(int oct){
    int digit, decimal = 0;
    int i = 0;

    while(oct!=0){
        digit = oct % 10;
        decimal = (digit * pow(8,i)) + decimal;
        i++;
        oct = oct / 10;
    }
    return decimal;
}

int main(){
    int oct;
    cout<<"\nNOTE: Entered Number must be Octal otherwise unexpected result!"<<endl;
    cout<<"Enter Octal Number:";
    cin>>oct;
    cout <<oct<<" in decimal is: "<<decimal(oct)<<endl<<endl;
    return 0;
}