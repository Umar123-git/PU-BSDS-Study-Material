
#include "Payroll.h"
using namespace std;



		void Payroll::loadEmployees()
		{
			

			// Create officer and daily_wager objects
			employees[0] = new officer("Ali", "HR", 17, 80000);
			employees[1] = new daily_wager("Ahmed", "Maintenance", 5, 1000, 4);
			employees[2] = new officer("Sara", "Finance", 18, 120000);

		}
		void Payroll::printSalaries() const
		{
			for (int i = 0; i < 3; ++i) {
				cout << "Employee " << i + 1 << " Info:\n";
				employees[i]->display();
				cout << "Take Home Income: " << employees[i]->take_home_income() << endl;
				cout << "-----------------------------------\n";
			}
		}
		Payroll::~Payroll(){
			for(int i=0 ; i<3 ; i++)
			{
				delete employees[i];
			}
		}