#ifndef assignment_2_Task_3_daily_wager_h
#define assignment_2_Task_3_daily_wager_h

#include "employee.h"

class daily_wager :public employee
{
private:
	int daily_wage;
	int absent_count;
public:
	daily_wager();

	daily_wager(string n, string d, int s, int w, int a) ;

	void setwage(int w);
	void setabsent(int a);

	int getwage()const;
	int getabsent()const;

	double take_home_income() const override ;
};



#endif