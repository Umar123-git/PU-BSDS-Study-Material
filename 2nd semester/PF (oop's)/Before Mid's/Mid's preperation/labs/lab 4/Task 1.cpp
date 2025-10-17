#include<iostream>
#include<cmath>
using namespace std;

class robot 
{ 	private: 
		string name; 
		int row, col; 
		char direction; // u(up), d(down), l(left), r(right) on Cartesian plane 
	public: 
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
			direction =d;
		} 
		void setRobot(string n, int cx, int cy, char d) 
		{
			name = n;
			direction=d;
			if(cx < 100 && cx >=0 && cy < 100 && cy >=0)
			{
				row=cx;
				col=cy;
			}
			else
			{
				cout<<"\ninvalid position \n";
			}
		} 
		bool canStep()
		{
			bool canstep=false;
			if(row < 100 && row >=0 && col < 100 && col >=0)
			{
				canstep=true;
			}
			return canstep;	
		} 
		void takeStep()
		{
			if(direction == 'u')
			{
				if(row > 0){
					row=row-1;
				}
			}
			if(direction == 'd')
			{
				if(row < 99){
					row=row+1;
				}
			}
			if(direction == 'l')
			{
				if(col >0){
					col=col-1;
				}
			}
			if(direction == 'r')
			{
				if(col < 99){
					col=col+1;
				}
			}
		} 
		void turnLeft ()
		{
			direction='l';
		} 
		void turnRight ()
		{
			direction='r';
		} 
		void turnBackword ()
		{
			direction='d';
		} 
		void display() const 
		{
			cout<<"\nRobot Name : "<<name;
			cout<<"\nLocation : "<<"Row : "<<row<<" Column : "<<col;
			cout<<"\nDirection : "<<direction<<endl;
		} 

}; 
int main()
{
	robot R;
	
	
	
	
	
	return 0;
}