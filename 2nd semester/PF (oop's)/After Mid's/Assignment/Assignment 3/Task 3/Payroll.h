#ifndef assignment_2_Task_3_Payroll_h
#define assignment_2_Task_3_Payroll_h

#include "employee.h"
#include "daily_wager.h"
#include "officer.h"
#include <iostream>
#include <string>
using namespace std;




class Payroll
{
	private:
		employee* employees[3];
	public:
		void loadEmployees();
		void printSalaries() const;
		~Payroll();
};


#endif