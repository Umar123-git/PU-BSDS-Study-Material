#include "class_Matrix33.h"

#include<iostream>
using namespace std;

int main()
{
	Matrix33 mat;
	double val,arr[3][3];
	int num;
	for(int col=0 ; col<=2 ; col++){
		for(int row=0 ; row<=2 ; row++){
			cin>>val;
			mat.setM(row , col , val);
		}
	}
	mat.display();
	
	
	for(int col=0 ; col<=2 ; col++){
		for(int row=0 ; row<=2 ; row++){
			cin>>arr[row][col];
		}
	}	
	
	mat.setM1(arr);
	
	cout<<"\nEnter number to find scalar product :";
	cin>>num;
	mat.multiply(num);
	
	mat.determinent();
	
	cout<<"\nCheck : "<<mat.check(arr);
	return 0;
}