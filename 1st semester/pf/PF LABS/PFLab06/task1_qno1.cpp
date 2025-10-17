#include<iostream>
using namespace std;
int sum(int);

int sum(int num){ 
    
    int reminder, sum = 0;
    while(num!=0){
        reminder = num % 10;
        sum = sum + reminder;  // add remider, which is last digit of num
        num = num / 10;
    }
    return sum;
}


int main(){
    int num;
    cout <<"Enter Number: ";  
    cin >>num;
    cout <<"Sum of digits of "<<num<<" is: "<<sum(num)<<endl;
    return 0;
}