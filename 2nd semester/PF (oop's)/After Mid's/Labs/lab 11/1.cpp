#include<iostream>
#include<string>
using namespace std;

class employee
{
	protected:
		string name;
		string department;
		int scale;
	public:
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
};

class daily_wager :public employee
{
private:
	int daily_wage;
	int absent_count;
public:
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
};




class officer:public employee
{
	protected:
		int salary;
		daily_wager c1;

		public:
		void setsalaray(int a){ salary = a;}
		void setdaily_wage(daily_wager b1) { c1 = b1;}

};


int main()
{
    
    officer o1;
    o1.setname("Ali");
    o1.setdepartment("HR");
    o1.setscale(17);
    o1.setsalaray(80000);

  
    daily_wager d1;
    d1.setname("Ahmed");
    d1.setdepartment("Maintenance");
    d1.setscale(5);
    d1.setwage(1000);       
    d1.setabsent(4);         

  
    cout << "Officer Info:\n";
    cout << "Name: " << o1.getname() << endl;
    cout << "Department: " << o1.getdepartment() << endl;
    cout << "Scale: " << o1.getscale() << endl;
    cout << "Monthly Salary: " << 80000 << endl;
   //cout << "Take Home Income (after 10% tax): " << o1.take_home_income() << endl;

    cout << "\n";

 
    cout << "Daily Wager Info:\n";
    cout << "Name: " << d1.getname() << endl;
    cout << "Department: " << d1.getdepartment() << endl;
    cout << "Scale: " << d1.getscale() << endl;
    cout << "Daily Wage: " << d1.getwage() << endl;
    cout << "Absent Days: " << d1.getabsent() << endl;
  //  cout << "Take Home Income (No tax): " << d1.take_home_income() << endl;

    return 0;
}
