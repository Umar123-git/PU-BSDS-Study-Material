#include<iostream>
#include"task 1.h"
#include<string>

		Student::Student()
		{
			roll="******";
			cgpa=0;
			name="null";
			cout<<"constructor";
		}
		void Student::setDetails()
		{
			string nam,rol;
			float cg;
			cout<<"enter student name : ";
			getline(cin,nam);
			name=nam;
			cin.ignore();
			cout<<"enter roll number : ";
			cin>>rol;
			roll=rol;
			cout<<"enter cgpa :";
			cin>>cg;
			cgpa=cg;
			
		}
		bool Student::check()
		{
			bool test =false;
			if(cgpa>=3.5)
			{
				test=true;
			}
			return test;
		}
		void Student::display()
		{
			cout<<"\nStudent Details :\n";
			cout<<"\nName : "<<name;
			cout<<"\nRoll Number : "<<roll;
			cout<<"\nCGPA : "<<cgpa<<endl;
		}