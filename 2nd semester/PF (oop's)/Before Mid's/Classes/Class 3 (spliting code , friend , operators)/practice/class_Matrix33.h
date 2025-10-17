#ifndef MYHEADER_H
#define MYHEADER_H


#include<iostream>
using namespace std;

class Matrix33
{
	protected:
		double m[3][3];
	public:
		void setM(int row, int col, double val)
		{
			m[row][col]=val;
		}
		double getM(int row , int col)
		{
			return m[row][col];
		}
		
			void display();
			void setM1(double arr[3][3]);
			Matrix33();				Matrix33(double n[3][3]);
			~Matrix33();
			void multiply(int num);
			double determinent();
			bool check(double arr[3][3]);
		
		
};

#endif


