#ifndef PERSON_H
#define PERSON_H


#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	private:
		double x , y ;	
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

		Point();
		Point(double p, double q);
	
		~Point();
	
		
		void disply() const;

};



class Line3D
{
	private:
		Point p1,p2;
	public:
		void setP1(Point _x)
		{
			p1=_x;
		}
		void setP2(Point _y)
		{
			p2=_y;
		}
		Point getP1() const
		{
			return p1;
		}
		Point getP2() const
		{
			return p2;
		}
		Line3D();
	
		Line3D(Point p, Point q);
	
		~Line3D();
	
		void disply() const;
	
  		Line3D operator=(const Line3D &p);
  	
		double slope() const ;
	
		void  Test_of_horizontal_and_vertical(const Line3D &a);
	
		
		void point_of_intersection(const Line3D& L1, const Line3D& L2);
		
		
		bool Parallel( Line3D& L1,  Line3D& L2);
	
		
	    double pointDistance(Point P) const ;
	
		bool Concurrent(const Line3D& L1, const Line3D& L2);
	
};

#endif