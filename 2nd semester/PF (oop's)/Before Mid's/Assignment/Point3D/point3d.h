#ifndef MYHEADER_H
#define MYHEADER_H


#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	private:
		double x , y , z;	
	public:
		void setX(double _x)
		{
			x=_x;
		}
		void setY(double _y)
		{
			y=_y;
		}
		void setZ(double _z)
		{
			z=_z;
		}
		double getX() const
		{
			return x;
		}
		double getY() const
		{
			return y;
		}
		double getZ() const
		{
			return z;
		}
		
		Point();
		Point(const Point &p);
		Point(double p, double q, double r);
		~Point();	
		void disply() const;
		double distance(const Point &p);
  		Point operator=(const Point &p);
		bool operator==(const Point &p);
  		Point operator+(const Point &p);
		Point operator-(const Point &p);
		friend ostream & operator<<(ostream & strm, Point & p);

};
#endif