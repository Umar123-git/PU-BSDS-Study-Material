#include<iostream>
#include<string>
using namespace std;


int main()
{
    string one[5];
    string two;
    int size;
    cout<<"enter the no. of parts of your name e.g(umar shafiq = 2) :";
    cin>>size;
    cout<<"enter your name :";
    for(int i=0 ; i<size ; i++)
    {
    	cin>>one[i];
    }
		two=one[1];

	cout<<"second part :"<<two;

    return 0;
}