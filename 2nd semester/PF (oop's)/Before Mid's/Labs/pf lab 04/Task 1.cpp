#include<iostream>
#include<cmath>
using namespace std;



class robot 
{ 
	private: 
		string name; 
		int row, col; 
		char direction; // u(up), d(down), l(left), r(right) on Cartesian plane 
	public: 
	
	robot()
	{
		name="null";
		row=0;
		col=0;
		direction='u';
	}
	
	void setrobot(const string &n , int r , int c , char d)
	{
		name=n;
		row=r;
		col=c;
		direction=d;
	}
	

		string getRobotName() const
		{
			return name;
		} 
		void setRobotName(string n)
		{
			name=n;
		}
	
		int getLocationX() const
		{
			return row;
		} 
		void setLocationX(int v) 
		{
			row=v;	
		} 
		
		int getLocationY() const
		{
			return col;
		} 
		void setLocationY(int v) 
		{
			col=v;
		} 
		
		char getDirection() const 
		{
			return direction;
		} 
		void setDirection (char d) 
		{
			direction = d;
		}
		 
	//	void setRobot(string n, int cx, int cy, char d) {} 
		bool canStep()
		{
			bool step=false;
			if(this->row >=0  &&  this->row <=99  &&  this->col >=0  &&  this->col <=99)
			{
				step=true;
			}
			return step;
		} 
		void takeStep()
		{
			if(this->row >=0  &&  this->row <=99  &&  this->col >=0  &&  this->col <=99)
			{
				cout<<"\nin which direction you wants to move press( u(up), d(down), l(left), r(right) )on Cartesian plane  :";
				char test;
				cin>>test;
				setDirection(test);		
				if(direction == 'u')
				{
					if(this->row <=99)
					{
						row=row+1;
					cout<<"Moved to Up : "<<row;
					}		
				}
				if(direction == 'd')
				{
					if(this->row >=0 )
					{
						row=row-1;
						cout<<"Moved to Down : "<<row;
					}
				}
				if(direction == 'l')
				{
					if(this->col >=0 )
						{
							col=col-1;
							cout<<"Moved to Left : "<<col;
						}
				}
				if(direction == 'r')
				{
					if(this->col <=99)
					{
						col=col+1;
						cout<<"Moved to Left : "<<col;	
					}
				
				}
			}
			cout<<endl;
		} 
		
		
		void takeStep(char p)
		{
			if(this->row >=0  &&  this->row <=99  &&  this->col >=0  &&  this->col <=99)
			{
				cout<<"\n";
				
				cout<<"direction : "<<direction<<"   ";	
				if(direction == 'u')
				{
					if(this->row <99 )
					{
						row=row+1;
					cout<<"Moved to Up : "<<row;
					}	
					else
					{
						cout<<"robot does not go outside the boundary";
					}	
				}
				if(direction == 'd')
				{
					if(this->row >0 )
					{
						row=row-1;
						cout<<"Moved to Down : "<<row;
					}
					else
					{
						cout<<"robot does not go outside the boundary";
					}
				}
				if(direction == 'l')
				{
					if(this->col >0)
						{
							col=col-1;
							cout<<"Moved to Left : "<<col;
						}
						else
					{
						cout<<"robot does not go outside the boundary";
					}
				}
				if(direction == 'r')
				{
					if(this->col <99)
					{
						col=col+1;
						cout<<"Moved to Left : "<<col;	
					}
					else
					{
						cout<<"robot does not go outside the boundary";
					}
				
				}
			}
			cout<<endl;
		} 
		void turnLeft (){} 
		void turnRight (){} 
		void turnBackword (){} 

		
		
		void disply() const
		{
			cout<<"Name of Robot : "<<this->name<<endl;
			cout<<"Location of Robot : "<<"("<<this->row<<","<<this->col<<")"<<endl;
			cout<<"Direction of Robot : "<<direction<<endl;
		}
		
}; 
/*
int main456()
{
	robot r;
	r.setLocationX(1);
	r.setLocationY(1);
	r.setRobotName("robot");
	r.setDirection('u');
	
	cout<<r.canStep();
	r.takeStep();
	r.disply();
	
	
	
	return 0;
}

int main12()
{
	robot r[6];
	
	for(int i=0 ; i<6 ; i++)
	{
		r[i].disply();
	}
	

	r[0].setrobot("R",0,0,'u');
	for(int i=0 ; i<4 ; i++)
	{
		r[0].takeStep('u');
	}
	r[0].disply();
	cout<<endl<<endl<<endl;
	
	
	r[1].setrobot("S",0,0,'u');
	for(int i=0 ; i<4 ; i++)
	{
		r[1].takeStep('u');
	}
	r[1].disply();
		cout<<endl<<endl<<endl;
		
		
	r[2].setrobot("T",0,0,'u');
	for(int i=0 ; i<4 ; i++)
	{
		r[2].takeStep('u');
	}
	r[2].disply();
		cout<<endl<<endl<<endl;
	
	r[3].setrobot("P",0,0,'u');
	for(int i=0 ; i<4 ; i++)
	{
		r[3].takeStep('u');
	}
	r[3].disply();
		cout<<endl<<endl<<endl;
		
		
		
	
	r[4].setrobot("Z",0,0,'d');
	for(int i=0 ; i<4 ; i++)
	{
		r[4].takeStep('u');
	}
	r[4].disply();
	cout<<endl<<endl<<endl;
	
	
	
	
	r[5].setrobot("T",0,0,'u');
	for(int i=0 ; i<4 ; i++)
	{
		r[5].takeStep('u');
	}
	r[5].disply();
		cout<<endl<<endl<<endl;
	
	return 0;
}*/

int main()
{
	robot r[6];
	
	for(int i=0 ; i<6 ; i++)
	{
		r[i].disply();
	}
		cout<<endl<<endl<<endl;
		
	r[0].setrobot("R",10,10,'u');
	r[0].disply();	
	cout<<endl<<endl<<endl;
	
	r[1].setrobot("S",10,20,'u');
	r[1].disply();
		cout<<endl<<endl<<endl;
	
//	r[2].setrobot("T",2,0,'u');
//	r[2].disply();
	
	r[2].setrobot("P",9,7,'u');
	r[2].disply();
		cout<<endl<<endl<<endl;
	
	r[3].setrobot("Z",25,12,'u');
	r[3].disply();
		cout<<endl<<endl<<endl;
	

	r[4].setrobot("T",0,0,'u');
	r[4].disply();
	cout<<endl<<endl<<endl;
	
	



	
	
	for(int i=0 ; i<3 ; i++)

	{
		if(r[4].getLocationX() != r[i].getLocationX()   ||  r[4].getLocationY() != r[i].getLocationY())
		{
					int adi=0,adj=0;
	int cor=0,coc=0;
			if(r[4].getLocationX()>r[i].getLocationX())
			{
					
					adi=r[4].getLocationX()-r[i].getLocationX();
					r[i].setDirection('u');
			}
			if(r[4].getLocationX()<r[i].getLocationX())
			{
				
					adi=r[i].getLocationX()-r[4].getLocationX();
					r[i].setDirection('d');
			}
		 	while(cor<=adi)
			{
				r[i].takeStep(r[i].getDirection());
				cor++;
			}
			
			if(r[4].getLocationY()>r[i].getLocationY())
			{
				
					adj=r[4].getLocationY()-r[i].getLocationY();
					r[i].setDirection('r');
			
			}
			if(r[4].getLocationY()<r[i].getLocationY())
			{
					
					adj=r[i].getLocationY()-r[4].getLocationY();
					r[i].setDirection('l');		
			}
	
			while(coc<=adj)
			{
				r[i].takeStep(r[i].getDirection());
				coc++;
			}
				if(r[4].getLocationX() == r[i].getLocationX()   ||  r[4].getLocationY() == r[i].getLocationY())
				{
					cout<<"Robot approaches at adjacent location to T \n";
				}
			
			r[i].disply();
			cout<<endl<<endl<<endl;
		}
			else
			{
				cout<<"Robot approaches at adjacent location to T \n";
					cout<<endl<<endl<<endl;
			}
	}
	


	return 0;
}

