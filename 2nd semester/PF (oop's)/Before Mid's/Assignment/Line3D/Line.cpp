#include "Line.h"
#include<iostream>
#include<cmath>
using namespace std;


		Point :: Point()
		{
			cout<<"default constructor of Point \n";
			x=0;
			y=0;
		//	disply();
		}

		Point :: Point(double p, double q)
		{
			cout<<"Double parameter constructor of Point  \n";
			x=p;
			y=q;
		}
		
		Point ::~Point()
		{
			cout<<"Distroying \n";
		}
		
		void Point :: disply() const
		{

			cout<<"("<<x<<","<<y<<")";
		}

		Line3D :: Line3D()
		{
			p1=Point(0,0);
			p2=Point(0,0);
		}

		Line3D :: Line3D(Point p, Point q)
		{
			cout<<"Double parameter constructor of Line  \n";
			p1=p;
			p2=q;
		}
		Line3D :: ~Line3D()
		{
			cout<<"Distroying \n";
		}
		
		void Line3D :: disply() const
		{
			cout<<"disply Line  ";
			this->p1.disply();
			cout<<" to ";
			this->p2.disply();
			cout<<endl;
		}
	
  		
  		
  		Line3D Line3D :: operator=(const Line3D &p)
  		{
  			p1=p.p1;
  			p2=p.p2;
  			cout<<"operator=  \n";
  			return *this;
		}
		
		
		double Line3D :: slope() const 
		{
       		if (p1.getX() == p2.getX())
			{
		   		cout<<"Vertical line has undefined slope";
			}
			
       		return (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    }
		
		void  Line3D :: Test_of_horizontal_and_vertical(const Line3D &a)
		{
			if(p1.getY()==p2.getY())
			{
				cout<<"Line is Horizontal  \n";
			}
			if(p1.getX()==p2.getX())
			{
				cout<<"Line is Vertical  \n";
			}
		}
		
		void Line3D :: point_of_intersection(const Line3D& L1, const Line3D& L2)
		{
			//line 1 (a,b)(c,d) 
			//line 2 (e,f)(g,h)
			double A1=L1.p2.getY()-L1.p1.getY();
			double B1=L1.p1.getX()-L1.p2.getX();
			double C1=(A1*L1.p1.getX()) + (B1*L1.p1.getY());
			
			double A2=L2.p2.getY() - L2.p1.getY();
			double B2=L2.p1.getX() - L2.p2.getX();
			double C2=(A2*L2.p1.getX())+(B2*L1.p1.getY());
			
			double det = A1 * B2 - A2 * B1;
			double x = (C1 * B2 - C2 * B1) / det;
        	double y = (A1  * C2 - A2 * C1) / det;
        	cout<<"("<<x<<","<<y<<")"<<endl;
			
		}
		
		bool Line3D :: Parallel( Line3D& L1,  Line3D& L2)
		{
			//line 1 (a,b)(c,d) 
			//line 2 (e,f)(g,h)
			bool test = false;
			if(L1.slope()==L2.slope())
			{
				test=true;
				cout<<"Lines are parallel to each other  ";
			}
			return test;
		}
		
	    double Line3D :: pointDistance(Point P) const 
			{
       			double A = p2.getY() - p1.getY();
        		double B = p1.getX() - p2.getX();
        		double C = A * p1.getX() + B * p1.getY();
        		return abs(A * P.getX() + B * P.getY() - C) / sqrt(A * A + B * B);
    		}


		bool Line3D :: Concurrent(const Line3D& L1, const Line3D& L2)
			//line 1 (a,b)(c,d) 
			//line 2 (e,f)(g,h)
		{
			bool test=false;
			double A3=L1.p2.getY()-L1.p1.getY();
			double B3=L1.p1.getX()-L1.p2.getX();
			double C3=A3*L1.p1.getX()+B3*L1.p2.getY();
			
			double A4=L2.p2.getY() - L2.p1.getY();
			double B4=L2.p1.getX() - L2.p2.getX();
			double C4=(A4*L2.p1.getX())+(B4*L1.p1.getY());
			
			double Deter=(A3*B4) - (A4*B3);
			if(Deter==0)
			{
				cout<<"the lines are parallel or coincident, meaning they do not intersect at a unique point  ";
			}
			if(Deter!=0)
			{
				cout<<"the lines intersect at a unique point, meaning they are concurrent.  ";
				test=true;
			}
			return test;
		}


