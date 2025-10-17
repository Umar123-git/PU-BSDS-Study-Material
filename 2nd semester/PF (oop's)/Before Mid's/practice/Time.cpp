#include<iostream>
using namespace std;


class Time
{
	protected:
		int time[3];
		
	public:
		void setTime(int tim, int which)
		{
			cout<<"void setT(int &tim)  "<<tim<<endl;
			if(which==0)
			{
				int i=time[0]+tim;
				while(i>23)
				{
					i=i-24;					
				}
				time[0]=i;
			}
			
			if(which==1)
			{
				int i=time[1]+tim;
				disply();
				while(i>59)
				{
					time[0]=time[0]+1;
					i=i-60;					
				}
				time[1]=i;
			}
			
			if(which==2)
			{
				int i=time[2]+tim;
				disply();
				while(i>59)
				{
					time[1]=time[1]+1;
					i=i-60;					
				}
				time[2]=i;
			}
		}	
		int getTime()const
		{
		//	cout<<"int getT()const  ";
		//	for(int i=0 ; i<3 ; i++)
		//	{
		//		return time[i];
		//		cout<<",";
		//	}
			return time[0];
		}
		
		Time()
		{
			cout<<"Time Constructor  \n";
			for(int i=0 ; i<3 ; i++)
			{
				 time[i]=0;
			}
		}
	
		void disply()const
		{
			cout<<"disply()  ";
			for(int i=0 ; i<3 ; i++)
			{
				cout<<time[i];
				cout<<",";
			}
			cout<<endl;
		}
	
	void add(int ad, int which)
	{
		cout<<"void add(int ad, int which)  "<<ad<<endl;
			if(which==0)
			{
				int i=time[0]+ad;
				while(i>23)
				{
					i=i-24;					
				}
				time[0]=i;
			}
			if(which==1)
			{
				int i=time[1]+ad;
				while(i>61)
				{
					time[0]=time[0]+1;
					i=i-60;					
				}
				time[1]=i;
			//	setTime(i,1);
			}
			if(which==2)
			{
				int i=time[2]+ad;
				disply();
				while(i>59)
				{
					time[1]=time[1]+1;
					i=i-60;					
				}
				time[2]=i;
			}
	}
	Time operator+(int ad)
	{
		cout<<"	void operator+(Time t, int ad, int which)  "<< endl;
		Time temp=*this;
		temp.add(ad,2);
		return temp;
	}
	
	Time& operator=(const Time &rhs)
	{
		cout<<"void operator=(const Time &rhs)  ";
		for(int i=0 ; i<3 ; i++)
		{
			this->time[i]=rhs.time[i];
		}
		return *this;
	}
	
friend ostream& operator<<(ostream & strm ,const Time & _time );
};


	
	ostream& operator<<(ostream & strm ,const Time & _time )
	{
		cout<<"void & operator<<(ostream & strm ,const Time & _time )  ";
		strm <<_time.getTime();
		return strm;
	}


int main()
{
	Time t,t2;
	
	t.add(24,0);
	t.disply();
	
	t.setTime(0,1);
	t.disply();
	
	t.add(60,2);
	t.disply();
	
	t.add(0,0);
	t.disply();
	
//	Time t2;
	cout<<"Time t2 \n";
	t.add(24,0);
	t2.disply();
	
	t2.setTime(0,1);
	t2.disply();
	
	t2.add(60,2);
	t2.disply();
	
	t2.add(0,0);
	t2.disply();
	
	
cout << "Total Hours: " << t.getTime() + t2.getTime() << endl;
	return 0;
}
