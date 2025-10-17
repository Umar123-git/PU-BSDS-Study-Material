#include<iostream>
#include<array>
using namespace std;
int search(array<int,50> , int, int);

int search(array<int,50> arr , int n, int v){  // n is the size of data set, and v is the typical number
    int i=0;
    while(i<n){
        cout<<"Enter Number at index "<<i<<" : ";
        cin >>arr[i];
        
        if (arr[i]==v){
            return i;  // result index
        }
        i++;
    }
    return -1;
}

int main(){
    array<int,50> arr;
    int n,v,index;
    cout <<"Enter Size of Data set: ";
    cin >>n;
    cout <<"Enter Typical Number: ";
    cin >>v;
    index = search(arr,n,v);

    if (index==-1){
        cout <<v <<" is Not present in the Data Set"<<endl;
    }
    else{
        cout <<v<<" is at index " <<index <<endl;
    }
    return 0;
}