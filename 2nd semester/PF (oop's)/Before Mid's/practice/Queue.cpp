#include<iostream>
using namespace std;


class Queue
{
	protected:
		int data[50];
		int size;
	public:
		int getSize() const
		{
			return size;
		}
		void setSize(const int &_size)
		{
			cout<<"setsize() \n";
			size=_size;
			cout<<"size of the queue is  = "<<size<<endl;

		}
		int getData() const
		{
			for(int j=0 ; j<=size ; j++)
			{
				return data[j];
			}
		}
		void setData(int &d)
		{
			data[size]=d;
			size++;
		}
		Queue()
		{
			for(int j=0 ; j<50 ; j++)
			{
				data[size]=0;
			}
		}
	
		void add(int add)
		{
		//	data[size]=add;
		//size++;
		cout<<"passing add function to setData function  ";
		setData(add);
		}
		
		void remove()
		{
			int rem=0;
			cout<<"removing  "<<data[0];
			for(int j=0 ; j<size ; j++)
			{
				data[j]=data[j+1];
				
			}
			rem++;
			size=size-rem;
		   cout<<endl;
		}
		
		bool isempty()
		{
			bool empty = false;
		//	cout<<size<<endl;
			if(size==0)
			{
				empty=true;
				cout<<"queue is empty "<<empty<<endl;
			}
			else
			{
				cout<<"queue is not empty "<<empty<<endl;
			}
			return empty;
		}
		
		bool isfull()
		{
			bool full=false;
			if(size==50)
			{
				full=true;
				cout<<"queue is full "<<full<<endl;
			}
			else
			{
				cout<<"queue is not full "<<full<<endl;
			}
			return full;
		}
		
		void disply()
		{
			cout<<"disply()  ";
			for(int j=0 ; j<size ; j++)
			{
				cout<<data[j]<<",";
			}	
			cout<<endl;
		}
		
		void numofpeople()
		{
			
		//	if(data[size]==0)
		//	{
		//		size--;
		//	}
			cout<<"size of the queue is :"<<size<<endl;
		}
		
 		 
		
};


int main()
{
	Queue q;
	
q.setSize(0);
	q.isempty();
	q.isfull();
		

	q.numofpeople();
	q.add(10);
	q.disply();
	q.numofpeople();
    q.add(46);
    q.disply();
    q.numofpeople();
    q.add(40);
	q.disply();
	q.numofpeople();
	q.remove();
	q.disply();
	q.numofpeople();
	q.add(23);
	q.disply();
	
	q.isempty();
	q.isfull();	
	q.remove();
	q.remove();
	q.disply();
	q.numofpeople();
	q.add(10);
	q.disply();
	q.numofpeople();
	q.add(10);
	q.numofpeople();
	q.disply();
	return 0;
}