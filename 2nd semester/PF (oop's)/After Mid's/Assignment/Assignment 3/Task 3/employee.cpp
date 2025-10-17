#include "employee.h"
#include "daily_wager.h"
#include<iostream>
#include<string>
#include<cmath>
using namespace std;


		employee::employee()
		{
			name="";
			department="";
			scale=0;
		}

		void employee::setname(string n)
		{
			name=n;
		}
		void employee::setdepartment(string d)
		{
			department=d;
		}
		void employee::setscale(int s)
		{
			scale=s;
		}
		string employee::getname()const{
			return name;
		}
		string employee::getdepartment()const{
			return department;
		}
		int employee::getscale()const{
			return scale;
		}

	double employee:: take_home_income() const {
        throw 0; 
        return 0;
    }

    void employee:: display() const {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Scale: " << scale << endl;
    }

