#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	private:
		double x , y;	
	public:
		void setX(double _x)
		{
			x=_x;
		}
		void setY(double _y)
		{
			y=_y;
		}

		double getX() const
		{
			return x;
		}
		double getY() const
		{
			return y;
		}

		Point()
		{
			cout<<"default constructor of Point \n";
			x=0;
			y=0;
		//	disply();
		}

		Point(double p, double q)
		{
			cout<<"Double parameter constructor of Point  \n";
			x=p;
			y=q;
		}
		
		~Point()
		{
			cout<<"Distroying \n";
		}
		
		void disply() const
		{

			cout<<"("<<x<<","<<y<<")";
		}


};



class Line3D
{
	private:
		Point *p1,*p2;
	public:
		void setP1(Point _x)
		{
			*p1=_x;
		}
		void setP2(Point _y)
		{
			*p2=_y;
		}
		Point getP1() const
		{
			return *p1;
		}
		Point getP2() const
		{
			return *p2;
		}
		Line3D()
		{
			p1=new Point(0,0);
			p2=new Point(0,0);
		}

		Line3D(Point p, Point q)
		{
			cout<<"Double parameter constructor of Line3D  \n";
			p1=new Point(p);
			p2=new Point(q);
		}
		
		~Line3D()
		{
			delete p1;
        	delete p2;
			cout<<"Distroying \n";
		}
		
		void disply() const
		{
			cout<<"disply Line  ";
			this->p1->disply();
			cout<<" to ";
			this->p2->disply();
			cout<<endl;
		}
	
  		
  		
  		Line3D operator=(const Line3D &rhs)
  		{
		    delete p1;
            delete p2;
            p1 = new Point(*rhs.p1);
            p2 = new Point(*rhs.p2);
		    cout << "Assignment operator called\n";
  			return *this;
		}
		
		
		
		double slope() const 
		{
       		if (p1->getX() == p2->getX())
			{
		   		("Vertical line has undefined slope");
			}
			
       		return (p2->getY() - p1->getY()) / (p2->getX() - p1->getX());
    }
		
		void  Test_of_horizontal_and_vertical(const Line3D &a)
		{
			if(p1->getY()==p2->getY())
			{
				cout<<"Line is Horizontal  \n";
			}
			if(p1->getX()==p2->getX())
			{
				cout<<"Line is Vertical  \n";
			}
		}
		
		friend void pointofintersection(const Line3D& L1, const Line3D& L2)
		{
			//line 1 (a,b)(c,d) 
			//line 2 (e,f)(g,h)
			double A1=L1.p2->getY()-L1.p1->getY();
			double B1=L1.p1->getX()-L1.p2->getX();
			double C1=(A1*L1.p1->getX()) + (B1*L1.p1->getY());
			
			double A2=L2.p2->getY() - L2.p1->getY();
			double B2=L2.p1->getX() - L2.p2->getX();
			double C2=(A2*L2.p1->getX())+(B2*L2.p1->getY());
			
			double det = A1 * B2 - A2 * B1;
			double x = (C1 * B2 - C2 * B1) / det;
        	double y = (A1  * C2 - A2 * C1) / det;
        	cout<<"("<<x<<","<<y<<")"<<endl;
			
		}
		
		bool Parallel( Line3D& L1,  Line3D& L2) const
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
		
	    double pointDistance(Point P) const 
		{
	        double A = p2->getY() - p1->getY();
	        double B = p1->getX() - p2->getX();
	        double C = A * p1->getX() + B * p1->getY();
	        return abs(A * P.getX() + B * P.getY() + C) / sqrt(A * A + B * B);
    	}


		bool Concurrent(const Line3D& L1, const Line3D& L2)
			//line 1 (a,b)(c,d) 
			//line 2 (e,f)(g,h)
		{
			bool test=false;
			double A3=L1.p2->getY()-L1.p1->getY();
			double B3=L1.p1->getX()-L1.p2->getX();
			double C3=A3*L1.p1->getX()+B3*L1.p2->getY();
			
			double A4=L2.p2->getY() - L2.p1->getY();
			double B4=L2.p1->getX() - L2.p2->getX();
			double C4=(A4*L2.p1->getX())+(B4*L1.p1->getY());
			
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
		
		
		bool isOnLine(const Point &p) const
		{
			return((p.getY()-p1->getY()) * (p2->getX()-p1->getX())) == ((p2->getY()-p1->getY()) * (p.getX()-p1->getX()));
		}
		
		Line3D(Line3D&& other)
		{
			p1=other.p1;
			p2=other.p2;
			cout << "Move constructor called\n";
			other.p1=nullptr;
			other.p2=nullptr;
		}
		// Copy Constructor
		Line3D(const Line3D& other) 
		{
		    p1 = new Point(*other.p1);
		    p2 = new Point(*other.p2);
		    cout << "Copy constructor called\n";
		}

};




int main()
{
    Point A(1,2), B(4,5), C(2,3), D(5,6);
    Line3D L1(A, B), L2(C, D);
    
    cout << "\nTesting Lines:" << endl;
    L1.disply();
    L2.disply();
    

    cout << "\nChecking if lines are parallel:" << endl;
    L1.Parallel(L1, L2);
    

    cout << "\nChecking if lines are concurrent:" << endl;
    L1.Concurrent(L1, L2);
    

    cout << "\nComputing Point of Intersection:" << endl;
    pointofintersection(L1, L2);

    cout << "\nChecking if lines are Horizontal or Vertical:" << endl;
    L1.Test_of_horizontal_and_vertical(L1);
    L2.Test_of_horizontal_and_vertical(L2);
    
	Point P(5, 6);
    
    
    cout << " from Line1: " << L1.pointDistance(P) << endl;
    cout<<"isOnLine :"<<L1.isOnLine(P)<<endl;
    return 0;
}
