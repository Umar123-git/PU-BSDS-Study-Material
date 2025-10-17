#ifndef assignment_2_Task_3_officer_h
#define assignment_2_Task_3_officer_h

#include "employee.h"
#include "daily_wager.h"
using namespace std;

class officer:public employee
{
	protected:
		int salary;
		daily_wager c1;

		public:
		void setsalaray(int a);
		void setdaily_wage(daily_wager b1) ;
	public:
		officer(string n, string d, int s, int sal) ;

	void display() const override ;

		double take_home_income() const override ;
};

#endif