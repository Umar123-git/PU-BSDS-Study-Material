#include "employee.h"
#include "officer.h"
#include "daily_wager.h"
#include<cmath>
using namespace std;



		officer::officer(string n, string d, int s, int sal) {
		name = n;
		department = d;
		scale = s;
		salary = sal;
	}

	void officer::display() const {
		employee::display();
		cout << "Salary: " << salary << endl;
	}

		double officer::take_home_income() const {
        return round(salary * 0.9); // 90% of monthly salary after tax
    }

