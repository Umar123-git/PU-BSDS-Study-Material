#include<iostream>
#include<cmath>
using namespace std;


class Vector4d
{
	protected:
		float w;
		float x;
		float y;
		float z;
	public:
		Vector4d()
		{
			w=0;
			x=0;
			y=0;
			z=0;
			cout<<"constructor\n";
		}
		~Vector4d()
		{
			cout<<"\ndestructor \n";
		}
		Vector4d(const float& a ,const float& b ,const float& c, const float& d)
		{
			w=a;
			x=b;
			y=c;
			z=d;
			cout<<"constructor\n";
		}
		
		float getw()const{ return w;	}
		float getx()const{ return x;	}
		float gety()const{ return y;	}
		float getz()const{ return z;	}
		
		double magnitude()
		{
			double m=w*w + x*x + y*y + z*z;
			return sqrt(m);		
		}
		
		bool unitvector()const
		{
			double m=w*w + x*x + y*y + z*z;
			return sqrt(m)==1;
		}
		
		double dotproduct(const Vector4d& v2)
		{
			cout<<"dot product :";
			return this->w*v2.w + this->x*v2.x + this->y*v2.y + this->z*v2.z;	
		}
		
		void difference(Vector4d& v2)
		{
			float a=this->w-v2.w;
			float b=this->x-v2.x;
			float c=this->y-v2.y;
			float d=this->z-v2.z;
			cout<<"\ndifference = ("<<a<<","<<b<<","<<c<<","<<d<<")";
		}
		
		void addinverse()
		{
			float a=-this->w;
			float b=-this->x;
			float c=-this->y;
			float d=-this->z;
			cout<<"\nadditive inverse = ("<<a<<","<<b<<","<<c<<","<<d<<")";
		}	
};
int main()
{
	Vector4d v1(1,2,0,0);
	cout<<v1.magnitude()<<endl;
	cout<<v1.unitvector()<<endl;
	
	Vector4d v2(1,2,3,4);
	cout<<v1.dotproduct(v2);
	v1.difference(v2);	
	v1.addinverse();
	
	return 0;
}