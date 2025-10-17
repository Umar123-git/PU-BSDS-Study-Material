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

int main()
{
   Course pf[4];
	for(int i=0 ; i<=5 ; i++)
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