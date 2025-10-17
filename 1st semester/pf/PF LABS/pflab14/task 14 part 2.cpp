#include<iostream>
#include<sstream>
#include<string>
using namespace std;



string maxlength(int size)
{
	string para[size];
	string max;
    for(int i=1 ; i!=0 ; i++)
    {
    	cin>>para[i];
    	if(para[i]=="stop")
    	{
    		break;
		}
		if(para[i].length()>max.length())
		{
			max=para[i];
		}
    }
	
	
	cout<<"max length word :"<<max;
	return max;
}





int main()
{
    string one;
    string max;
    int size=100;
    cout<<"enter the paragraph to end the paragraph enter (stop):";
	maxlength(size);



    return 0;
}