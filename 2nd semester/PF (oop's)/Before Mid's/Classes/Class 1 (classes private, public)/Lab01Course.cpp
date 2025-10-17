#include<iostream>
#include<string>

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
    Course pf;
    pf.setCode("CC-211");
    pf.setTitle("Programing Fundamentals");
    pf.setCreditHours(3);
    
    cout << "Details of PF are" << endl;
    cout << "Code   : " << pf.getCode() << endl;
    cout << "Title  : " << pf.getTitle() << endl;
    cout << "Credits: " << pf.getCreditHours() << endl;
    
	return 0;
}
