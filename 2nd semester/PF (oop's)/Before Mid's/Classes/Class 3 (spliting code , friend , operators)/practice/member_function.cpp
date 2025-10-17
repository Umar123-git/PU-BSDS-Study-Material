
#include "class_Matrix33.h"

using namespace std;

		void Matrix33::display()
		{
			cout<<endl;
			for(int col=0 ; col<=2 ; col++){
			   	for(int row=0 ; row<=2 ; row++){
					 cout<<m[row][col]<<"  ";
				}
				cout<<endl;
			}

			cout<<endl;
		}
		
		
		
		void Matrix33::setM1(double arr[3][3])
		{
			for(int col=0 ; col<=2 ; col++){
				for(int row=0 ; row<=2 ; row++){
					m[row][col]=arr[row][col];
				}
			}
			
			display();
		}
		
		
	Matrix33::Matrix33()
		{
			for(int col=0 ; col<=2 ; col++){
				for(int row=0 ; row<=2 ; row++){
					m[row][col]=0;
				}
			}
		}
		
	Matrix33::Matrix33(double n[3][3])
		{
			for(int col=0 ; col<=2 ; col++){
				for(int row=0 ; row<=2 ; row++){
					m[row][col]=n[row][col];
				}
			}
		}		
		
		
	Matrix33::~Matrix33()
		{
			cout<<"\nI am dying ...\n";
		}
		
		
	void Matrix33::multiply(int num)
		{
			for(int col=0 ; col<=2 ; col++){
				for(int row=0 ; row<=2 ; row++){
					m[row][col]=m[row][col]*num;
				}
			}
			cout<<"\nScalar product of 3x3 is :\n";
			display();
		}
		
		
	double Matrix33::determinent()
		{
			double d;
			d=m[0][0]*((m[1][1]*m[2][2])-(m[1][2]*m[2][1]))   -   m[0][1]*((m[1][0]*m[2][2])-(m[1][2]*m[2][0]))  +  m[0][2]*((m[1][0]*m[2][1]-m[1][1]*m[2][0]));
		cout<<"\nDeterminent is equal to :"<<d;
		return d;
		}
		
		
		bool Matrix33::check(double arr[3][3])
		{
			bool check=true;
			for(int col=0 ; col<=2 ; col++){
				for(int row=0 ; row<=2 ; row++){
					if(m[row][col]!=arr[row][col])
					{
						check=false;
						return check;
					}
				}
			}
			return check;
		}