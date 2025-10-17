#include <iostream> 
#include <string>

using namespace std;


struct Student{
	int rollno;
	string name;
	float matric;
	float intermediate;
};


int main()
{
	
	Student student;
	Student* p = &student;
	
	cout<<"enter the roll no.:";
	cin>>(*p).rollno;
	cout<<"enter the name :";
	cin>>(*p).name;
	cout<<"enter matric marks :";
	cin>>(*p).matric;
	cout<<"enter intermediate marks :";
	cin>>(*p).intermediate;
	
	cout<<endl;
	cout<<"student details :"<<endl;
	
    cout<<"roll no: "<<(*p).rollno << endl;
    cout<<"name: "<<(*p).name<< endl;
    cout<<"matric marks: "<<(*p).matric << endl;
    cout<<"intermediate marks: "<<(*p).intermediate << endl;
	return 0;
	
}