#include<iostream>
#include<string>
#include<array>
#include<cmath>

using namespace std;

class Course
{
    private:
        string code;
        string title;
        float creditHours;
    public:
        string getCode()
        {
            return code;
        }
        
        void setCode(string _code)
        {
            code = _code;
        }
        
        string getTitle()
        {
            return title;
        }
        
        void setTitle(string _title)
        {
            title = _title;
        }
        
        float getCreditHours()
        {
            return creditHours;
        }
        
        void setCreditHours(float _crHrs)
        {
            creditHours = _crHrs;
        }
        
        void Display()
        {
        	cout << "Details of PF are" << endl;
		    cout << "Code   : " << code << endl;
		    cout << "Title  : " << title << endl;
		    cout << "Credits: " << creditHours << endl;
		}
        
};
class Student
{
	private:
		string rollno;
		string name;
		float credithours;
		Course course[3];
	public:
		Course getcourse(int i)
		{
			return course[i];
		}
		void setcourse(int i,Course _course)
		{
			course[i] = _course;
		}
		string getrollno()
		{
			return rollno;
		}
		string getname()
		{
			return name;
		}	
		float getcredithours()
		{
			return credithours;
		}
		void setrollno(string& r)
		{
			rollno=r;
		}
		void setname(string& n)
		{
			name=n;
		}
		void setcredithours(float c)
		{
			credithours=c;
		}
		
		void display()
        {
        	cout<<"Name : "<<name;
        	cout<<"\nRoll No. : "<<rollno;
        	cout<<"\nCredit Hours : "<<credithours;
        	for (int i = 0; i < 3; i++) {
            course[i].Display();
            cout << endl;
        }
		}
};

int maint1()
{
   Course pf[4];
	for(int i=0 ; i<=4 ; i++)
	{
	pf[i].setCode("CC-211");
    pf[i].setTitle("Programing Fundamentals");
    pf[i].setCreditHours(3);
		
		
		
		
		
	cout << "Details of PF are" << endl;
    cout << "Code   : " << pf[i].getCode() << endl;
    cout << "Title  : " << pf[i].getTitle() << endl;
    cout << "Credits: " << pf[i].getCreditHours() << endl;
    
    
    cout<<endl;
    
}
	return 0;
}


int maint2()
{
   Course* pf[4];
   
	for(int i=0 ; i<=4 ; i++)
	{
		pf[i]=new Course;
	pf[i]->setCode("CC-211");
    pf[i]->setTitle("Programing Fundamentals");
    pf[i]->setCreditHours(3);	
		
		
		
		
	cout << "Details of PF are" << endl;
    cout << "Code   : " << pf[i]->getCode() << endl;
    cout << "Title  : " << pf[i]->getTitle() << endl;
    cout << "Credits: " << pf[i]->getCreditHours() << endl;
    
    
    
    cout<<endl;
    
}
	for(int i=0 ; i<=4 ; i++)
	{
		delete[] pf[i];
	}

	return 0;
}
	
	
int maint3()
{
	 Course c1;
    c1.setCode("CC-211");
    c1.setTitle("Programming Fundamentals");
    c1.setCreditHours(3);
	string roll,nam;
	
	float hrs;
	Student student[4];
	
	for(int i=0 ; i<3 ; i++)
	{
		cout<<"enter roll number :";
		cin>>roll;
	student[i].setrollno(roll);
	
		cout<<"enter Name :";
		cin>>nam;
    student[i].setname(nam);
	
		cout<<"enter Credit Hours :";
		cin>>hrs;
    student[i].setcredithours(3);	
    
    cout<<"course :";
    student[i].setcourse(i,c1);
    
	
	
	cout<<endl;	
		
	 } 	
		
	cout << "Details of Student is" << endl <<endl;
	student[0].display();
	
	return 0;
}

int main()

