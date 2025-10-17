#include<iostream>
#include<cmath>
using namespace std;
	
	
		
class Student
{
	private:
		string name;
		int age;	
		
	public:
		string getName()
		{
			return name;
		}
		
		int getAge()
		{
			return age;
		}
		
		void setName(string _name)
		{
			name=_name;
		}
		
		void setAge(int _age)
		{
			age = _age;
		}
		
		void disply()
		{
			cout<<endl<<"Name = "<<getName()<<endl<<"Age = "<< getAge();
		}
};
	
	
int main()
{
	Student s;
	string n;
	int a;
	cout<<"Enter Name :";
	getline(cin , n);
	cout<<"Enter Age :";
	cin>>a;
	
	s.setName(n);
	s.setAge(a);
	
	
	s.disply();
	
	
	return 0;
}