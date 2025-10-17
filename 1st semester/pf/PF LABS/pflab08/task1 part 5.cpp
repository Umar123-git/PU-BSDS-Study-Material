#include<iostream>
#include<array>
#include<cmath>
using namespace std;

struct student
{
	int rollno;
	string name;
	float percentmarks;
};

bool compare(student a, student b)
{

     return a.percentmarks<b.percentmarks;
}





int main()
{
	array<student,100> students;
	int n;
	cout<<"enter the number of students :";
	cin>>n;
    int i=0;
    while(i<=n)
    {
    	cout<<"student No. "<<i+1<<endl;
    	cout<<"roll no. ";
    	cin>>student.rollno;
    	cout<<"Name ";
    	cin>>student.name;
    	cout<<"marks ";
    	cin>>student.percentmarks;
    	

	}
	return 0;
}