#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class employee
{
	protected:
		string name;
		string department;
		int scale;
	public:
		employee()
		{
			name="";
			department="";
			scale=0;
		}

		void setname(string n)
		{
			name=n;
		}
		void setdepartment(string d)
		{
			department=d;
		}
		void setscale(int s)
		{
			scale=s;
		}
		string getname()const{
			return name;
		}
		string getdepartment()const{
			return department;
		}
		int getscale()const{
			return scale;
		}

		virtual double take_home_income() const {
        throw 0; 
        return 0;
    }

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Scale: " << scale << endl;
    }
};

class daily_wager :public employee
{
private:
	int daily_wage;
	int absent_count;
public:
	daily_wager()
	{
		daily_wage=0;
		absent_count=0;
	}

	daily_wager(string n, string d, int s, int w, int a) {
		name = n;
		department = d;
		scale = s;
		daily_wage = w;
		absent_count = a;
	}

	void setwage(int w)
	{
		daily_wage=w;
	}
	void setabsent(int a)
	{
		absent_count=a;
	}

	int getwage()const
	{
		return daily_wage;
	}
	int getabsent()const
	{
		return absent_count;
	}

	double take_home_income() const override {
        int working_days = 30 - absent_count; // Assuming 30 days in a month
        return daily_wage * working_days;    // No tax for daily wagers
    }
};




class officer:public employee
{
	protected:
		int salary;
		daily_wager c1;

		public:
		void setsalaray(int a){ salary = a;}
		void setdaily_wage(daily_wager b1) { c1 = b1;}
	public:
		officer(string n, string d, int s, int sal) {
		name = n;
		department = d;
		scale = s;
		salary = sal;
	}

	void display() const override {
		employee::display();
		cout << "Salary: " << salary << endl;
	}

		double take_home_income() const override {
        return round(salary * 0.9); // 90% of monthly salary after tax
    }

};


int main() {
    // Create an array of pointers to employee objects
    employee* employees[3];

    // Create officer and daily_wager objects
    employees[0] = new officer("Ali", "HR", 17, 80000);
    employees[1] = new daily_wager("Ahmed", "Maintenance", 5, 1000, 4);
    employees[2] = new officer("Sara", "Finance", 18, 120000);

    // Display information and take home income for each employee
    for (int i = 0; i < 3; ++i) {
        cout << "Employee " << i + 1 << " Info:\n";
        employees[i]->display();
		cout << "Take Home Income: " << employees[i]->take_home_income() << endl;
        cout << "-----------------------------------\n";
    }

    // Clean up memory to avoid leaks
    for (int i = 0; i < 3; ++i) {
        delete employees[i];
    }

    return 0;
}
