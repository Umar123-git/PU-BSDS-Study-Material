#include<iostream>
#include<array>
using namespace std;
int sum(array<int,20> num);

int sum(array<int,20> num){
    int i = 0;
    while(i<5){
        if(num[i]<0){
            num[i] = num[i]/-1; // to make absolute value
        }
        i++;
    }
    int j=0;
    int sum = 0;
    while(j<5){
        if(num[j]>=7000){
            sum = sum + num[j];
        }
        j++;
    }
    return sum;
}

int main(){
    array<int,20> num;
    int i=0;
    while(i<5){
        cout<<"Enter value in range -10,000 to +10,000: ";
        cin>>num[i];
        i = i+1;
    }
    cout <<"Sum of absolute values greater then 7000 is: "<<sum(num)<<endl;
    return 0;
}