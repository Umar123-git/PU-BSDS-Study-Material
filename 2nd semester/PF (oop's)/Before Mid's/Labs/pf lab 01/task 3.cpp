#include<iostream>
#include<string>
#include<array>

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
        
};


class Student
{
    private:
        string rollnum;
        string name;
        float creditHours;
        Course course[3];
    public:
        string getRollnum()
        {
            return rollnum;
        }
        
        void setRollnum(string _rollnum)
        {
            rollnum = _rollnum;
        }
        
        string getName()
        {
            return name;
        }
        
        void setName(string _name)
        {
            name = _name;
        }
        
        float getCreditHours()
        {
            return creditHours;
        }
        
        void setCreditHours(float _crHrs)
        {
            creditHours = _crHrs;
        }
        
    Course getCourse(int index) {
         {
            return course[index];
        }
        return Course(); 
    }

    void setCourse(int index, Course _course)
		 {
            course[index] = _course;
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
	Course *pf[4];
		for(int i=0 ; i<=4 ; i++)
	{ 
	pf[i]=new Course;
	}
	
	for(int i=0 ; i<=4 ; i++)
	{
	
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
		delete pf[i];
	}
		
	
	return 0;
}


int main()
{
	string roll,nam;
	float hrs;
	Student student[4];
	
	for(int i=0 ; i<3 ; i++)
	{
		cout<<"enter roll number :";
		cin>>roll;
	student[i].setRollnum(roll);
	
		cout<<"enter Name :";
		cin>>nam;
    student[i].setName(nam);
	
		cout<<"enter Credit Hours :";
		cin>>hrs;
    student[i].setCreditHours(3);	
	
	
	cout<<endl;	
		
	 } 
	

		
		
		
		
	cout << "Details of Student is" << endl <<endl;
	
	
	for(int i=0 ; i<3 ; i++)
	{
    cout << "Code   : " << student[i].getRollnum() << endl;
    cout << "Title  : " << student[i].getName() << endl;
    cout << "Credits: " << student[i].getCreditHours() << endl;	
    cout<<endl;
	}


	return 0;
}




