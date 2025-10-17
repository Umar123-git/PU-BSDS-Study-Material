#include<iostream>
#include<array>
#include<string>
using namespace std;


void reverse(const string& word)
{
	int i=0;
	while(i<word.length())
	{
		i++;
	}
	cout<<i;
}





int main()
{
	string word;
	cout<<"enter the word :";
	cin>>word;

	
	reverse(word);
	
	
	
	
	
	
	
	
	return 0;
}