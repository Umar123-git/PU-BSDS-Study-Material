#include<iostream>
using namespace std;

int main()
{
   float a,b,i=1,max=0;
   cout<<"Enter count values :";
   cin>>a;
   while(i<=a)
   {
   	cin>>b;
   	if(b>max)
   	{
   		max=b;
	}
     i=i+1;
   }
   cout<<"max ="<<max<<endl;
   return 0;
}