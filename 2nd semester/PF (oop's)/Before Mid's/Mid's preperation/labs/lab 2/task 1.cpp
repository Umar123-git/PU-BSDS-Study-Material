#include<iostream>
using namespace std;

class Matrix33
{
	private:
		double m[3][3];
	public:
		Matrix33()
		{
			int p=1;
			for(int i=0 ; i<3 ; i++)
			{
				for(int j=0 ; i<3 ; j++)
				{
					m[j][i]=p;
					p++;
				}
			}
		}
		
		double determinent()
		{
			double det=m[1][1]*(m[2][2]*m[3][3] - m[3][2]*m[2][3]) - m[1][2]*m[2][2];
		}
		
		double getElement(int row, int col)
		{
			return m[row][col];
		}
		void setElement(int row, int col , double val)
		{
			m[row][col]=val;
		}
		void setElement(double arr[])
		{
			for(int i=0 ; i<3 ; i++)
			{
				for(int j=0 ; i<3 ; j++)
				{
					m[j][i]=arr[j];
				}
			}
		}
		
		void display()
		{
			cout<<"display : ";
			for(int i=0 ; i<3 ; i++)
			{
				for(int j=0 ; i<3 ; j++)
				{
					cout<<m[j][i]<<" ";
				}
			}
		}
};

int main()
{
	Matrix33 m;
	
	
	
	
	return 0;
}