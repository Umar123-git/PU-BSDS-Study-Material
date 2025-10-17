#include<iostream>
#include<array>
#include<string>
using namespace std;

class SaleIteam
{
	protected:
		int qty;
		int rate;
		string desc;
	public:
	int getrate(){return rate;}
	int getqty() {return qty;}
	
	void input()
	{
		cout<<"Description :";
		cin.ignore();
		getline(cin,desc);
		cout<<"Quantity : ";
		cin>>qty;
		cout<<"Rate : ";
		cin>>rate;
		
	}
	void display() const {
        cout << "Description: " << desc << ", Qty: " << qty << ", Rate: " << rate << endl;
    }
		
};

class Cashmemo
{
	protected:
		int srno;
		int p;
		string date;
		string name;
		string addr;
		double tel;
		int totalamount;
		array<SaleIteam,4>si;
		
	public:
		void inputdetails()
		{
			cout<<"Sr No. : ";
			cin>>srno;
			cout<<"Date : ";
			cin>>date;
			cout<<"Name : ";
			cin.ignore();
			getline(cin,name);
			cout<<"Cell No. : ";
			cin>>tel;
			cout<<"Address : ";
			cin.ignore();
			getline(cin,addr);
			cout<<"Sale Iteam : \n";
			cout<<"We have every type of phones and accessories \n1) Phone , 2) Battery , 3) Handfree , 4) Speakers \n\nType the No. of type of Thing You wants to buy :";
			cin>>p;
			for(int i=0 ; i<p ; i++)
			{
				si[i].input();
				cout<<endl;
			}
		}
		double calculatetotal()
		{
			int j=0,t=0;
			for(int i=0 ; i<p ; i++)
			{
				j=si[i].getrate()*si[i].getqty();
				t=t+j;
			}
			cout<<"Your total Amount = "<<t<<endl;
			return t;
		}
		
		
		
		void disply()
		{
			cout<<"			  MOBILO\n			MOBILE SHOP\n";
			cout<<"\n\nSr No. : "<<srno<<endl;
			cout<<"Date : "<<date<<endl;
			cout<<"Name : "<<name<<endl;
			cout<<"Cell No. : "<<tel<<endl;
			cout<<"Address : "<<addr<<endl;
			cout<<"Sale Iteam : \n";
			for(int i=0 ; i<p ; i++)
			{
				si[i].display();
			}
			calculatetotal();
		}
		
};

int main()
{
	Cashmemo c;
	c.inputdetails();
	c.disply();
	
	return 0;
}