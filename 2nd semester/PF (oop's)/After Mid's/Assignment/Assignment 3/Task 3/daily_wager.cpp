#include "daily_wager.h"
#include "employee.h"
//#include<string>
//#include<cmath>



	daily_wager::daily_wager()
	{
		daily_wage=0;
		absent_count=0;
	}

	daily_wager::daily_wager(string n, string d, int s, int w, int a) {
		name = n;
		department = d;
		scale = s;
		daily_wage = w;
		absent_count = a;
	}

	void daily_wager::setwage(int w)
	{
		daily_wage=w;
	}
	void daily_wager::setabsent(int a)
	{
		absent_count=a;
	}

	int daily_wager::getwage()const
	{
		return daily_wage;
	}
	int daily_wager::getabsent()const
	{
		return absent_count;
	}

	double daily_wager::take_home_income() const{
        int working_days = 30 - absent_count; // Assuming 30 days in a month
        return daily_wage * working_days;    // No tax for daily wagers
    }

