#include<iostream>
#include<array>
using namespace std;


int main()
{
	int arr[5]={15 , 7 , 31 , 1 , -2};

  for (int i=0 ; i<5 ; i++)
  {
	cout<<arr[i]<<" ";
  }
  cout<<endl;
 char* p = static_cast<char*>(static_cast<void*>(arr));
 
 
    for (int i = 0; i < 20; i++) { 
        cout << i <<"  "<< p[i] << " "<< (int)p[i] << endl;
    }
	return 0;
}