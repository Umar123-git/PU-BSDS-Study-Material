#include<iostream>
using namespace std;

class StudentRecords
{
	private:
		int studentID;
		string name;
		double grades[5];
		
	public:
		int getStudentID()
		{
			return studentID;	
		}	
		
		void setStudentID(int s)
		{
			studentID=s;
		}
	
	
		string getName()
		{
			return name;
		}
		
		void setName(string n)
		{
			name=n;
		}
	
		double getGrades()
		{		
			for(int i=0 ; i<5 ; i++)
			{
				return grades[i];
			}	
		}
	
		void setGrade(double g[])
		{
			for(int i=0 ; i<5 ; i++)
			{
				grades[i]=g[i];
			}
		}
		
		
		double GPA();
		void display();

	
};


	double StudentRecords:: GPA()
		{
			double gpa=0;
			for(int i=0 ; i<5 ; i++)
			{
				gpa=gpa+grades[i];
			}
				gpa=gpa/5;
		
			return gpa;
		}


	void StudentRecords:: display()
	{
		cout<<"GPA :"<<GPA()<<endl;
	}


int main()
{
	StudentRecords sr;
	
	int id;
	string nam;
	
	for(int j=0 ; j<3 ; j++)
	{
		double grad[5];
		
		cout<<"Student ID :";
		cin>>id;
		sr.setStudentID(id);
		
		
		cout<<"Name :";
	//	getline(cin , nam);
		cin>>nam;
		sr.setName(nam);
	
		
		cout<<"Grades :";
		for(int i=0 ; i<5 ; i++)
		{
			cin>>grad[i];
		}
		sr.setGrade(grad);
	
		sr.display();
		
		cout<<"\n\n";
	}

	
	
	
	return 0;
}