#include<iostream>
using namespace std;



	struct area{
		int length;
		int width;

	};
	
	struct shape{
		string shape;
		area*p;
	};
	

int main(){
	
	shape s;
	s.p=new area;
	cout<<"enter the shape of the object :";
	cin>>s.shape;

	cout<<"enter the length and width of the rectangle :";
	cin>>s.p->length >>s.p->width;
	int length=s.p->length ; int width=s.p->width;
	cout<<endl;
	int area=length*width;
	cout<<"area of rectangle  :"<<area;
	
	
	delete[]s.p;
	
	return 0;
}