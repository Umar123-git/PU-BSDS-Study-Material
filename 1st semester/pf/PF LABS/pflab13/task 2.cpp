#include<iostream>
#include<array>
#include<string>
using namespace std;


string reverse(const string& word)
{
	string reversed="";

	for(int i=word.length()-1;i>=0;i--)
	{
		reversed +=word[i];
	}
	return reversed;
}





int main()
{
	string word;
	cout<<"enter the word :";
	cin>>word;

	
	cout<<reverse(word);
	
	
	
	
	
	
	
	
	return 0;
}