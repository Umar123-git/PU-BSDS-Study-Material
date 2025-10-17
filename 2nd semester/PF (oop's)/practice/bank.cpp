#include <iostream>
#include <cmath>
using namespace std;
	

	
		
class BankAccount
{
	private:
		double accountnum;
		long double balance;	
		
	public:
		double getAccountnum()
		{
			return accountnum;
		}
		
		long double getBalance()
		{
			return balance;
		}
		
		void setAccountnum(double _accountnum)
		{
			accountnum=_accountnum;
		}
		
		void setBalance(int _balance)
		{
			balance = _balance;
		}
		
		
		long double deposit(double d)
		{
			double sum;
			sum=balance+d;
			balance=sum;
			cout<<"Now your balance is :"<<balance<<endl;
			return sum;
		}
		
		long double withdraw(double w)
		{
			double wd;
			wd=balance-w;
			balance=wd;
			return wd;
		}
		
};
	
	
int main()
{
	BankAccount ba;
	double an,dp,wd, bal=10000;
	char y1,y2;
	
	cout<<"Enter Account No. :";
	cin>>an;
	
	ba.setAccountnum(an);
	ba.setBalance(bal);
	
	
	cout<<endl<<"Balance in your account :"<<ba.getBalance();
	cout<<endl;
	
	cout<<"Do you wants to deposit money than press Y otherwise press N ( Y / N ) :";
	cin>>y1;
	if(y1=='y' || y1=='Y')
	{
		
		cout<<"Enter money you wants to deposit :";
		cin>>dp;
		ba.deposit(dp);
		
	}
	
	cout<<"Do you wants to withdraw money than press Y otherwise press N ( Y / N ) :";
	cin>>y2;
	if(y2=='y' || y2=='Y')
	{
		cout<<"Enter money you want to withdraw :";
		cin>>wd;
		
		cout<<"Take your money :"<<wd<<endl;
		ba.withdraw(wd);
		cout<<"The remaining balance is :"<<ba.getBalance();
		
		
	}
	
	
	return 0;
}