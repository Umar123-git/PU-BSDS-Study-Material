#ifndef assignment_2_Task_3_employee_h
#define assignment_2_Task_3_employee_h

#include<iostream>
using namespace std;

class employee
{
	protected:
		string name;
		string department;
		int scale;
	public:
		employee();
		void setname(string n);
		void setdepartment(string d);
		void setscale(int s);
		string getname()const;
		string getdepartment()const;
		int getscale()const;

		virtual double take_home_income() const;
        virtual void display() const ;
};

#endif