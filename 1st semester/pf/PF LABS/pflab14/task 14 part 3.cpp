#include<iostream>
#include<cstring>

using namespace std;


int main()
{
    char one[5][50];
    char two[50];
    int size;
    cout<<"enter the no. of parts of your name e.g(umar shafiq = 2) :";
    cin>>size;
    cout<<"enter your name :";
    for(int i=0 ; i<size ; i++)
    {
    	cin>>one[i];
    }
	
		 strcpy(two, one[1]);

	cout<<"second part :"<<two;

    return 0;
}