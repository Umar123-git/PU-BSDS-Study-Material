#include<iostream>
#include<cmath>
#include<array>
using namespace std;

class Bag
{
	protected:
		array<string,10> pocket;
	public:
		
		Bag()
		{
			cout<<"default constructor \n";
		}
		
		Bag(const string a , int n)
		{
			cout<<"constructor \n"<<n<<endl;
	 		pocket[n]=a;
			cout<<pocket[n]<<endl;
			n++;
		}
		
		~Bag()
		{
			cout<<"destructor \n";
		}
		
		void null()
		{
			for(int i=0 ; i<10 ; i++)
			{
				pocket[i]="empty";
			}
		}
		
		void add()
		{
			string a; int z;
			cout<<"enter the iteam you wants to place into the bag :";
			getline(cin,a);
			cout<<"there are only 10 pockets in the Bag from 0 - 9 enter the pocket No. ";
			cin>>z;
			
			if(z<10 && z>=0)
			{
				cout<<pocket[z]<<endl;
			}
			else
			{
				cout<<"pocket No. is invalid \n";
			}
			cin.ignore();
			//return pocket[z];
		}
		
		bool search()
		{
			string a;
			
			cout<<"type the iteam you want to find :";
			getline(cin,a);
			bool search = false;
			cout<<"searching ... \n";
			for(int i=0 ; i<10 ; i++)
			{
				if(pocket[i]==a)
				{
					search =true;
					return search;
				}
			
			}
			cout<<"iteam not found  ";
			cin.ignore();
			return search;
		}
		
		bool isempty()
		{
			bool empty=true;
			for(int i=0 ; i<10 ; i++)
			{
				if(pocket[i]!="empty")
				{
					empty=false;
					cout<<"Bag is not empty ";
					return empty;
				}
				
			}
			cout<<"Bag is empty ";
			return empty;
		}
		
		bool isfull()
		{
			bool full=true;
			for(int i=0 ; i<10 ; i++)
			{
				if(pocket[i]=="empty")
				{
					full=false;
					cout<<"Bag is not full ";
					return full;
				}
				
			}
			cout<<"Bag is full ";
			return full;
		}
	
	
	void display()const
	{
		cout<<"display \n";
		for(int i=0 ; i<10 ; i++)
			{
				if(pocket[i]!="empty")
				{
					cout<<"Pocket No. :"<<i<<"  "<<"iteam :"<<pocket[i]<<endl;
				}		
			}
	}
	
	
};

int main()
{	
	Bag b;
	b.null();
	b.add();
	cout<<b.search()<<endl;
	cout<<b.isempty()<<endl;
	cout<<b.isfull()<<endl;
	b.display();
	
	
	
	
	
	
	
	
	return 0;
}