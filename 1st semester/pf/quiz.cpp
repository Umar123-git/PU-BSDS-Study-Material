#include<iostream>
#include<cmath>
using namespace std;
/*
bool ascending(int ar[],int N)
{
	bool as=true;
	int i=0;
	while(i<=N)
	{
		if(ar[i]>ar[i+1]  ||  ar[i]<ar[i+1])
		{
			 cout<<"efg"<<endl;
			as=false;
			cout<<as;
		}
		i++;
	}
	return as;
}
*/
int main()
{
	/*int ar[1],N=2;
    cin>>ar[0];
    cin>>ar[1];
   
    ascending( ar, N);*/
    
   /* int a=10;
    int *p = &a;
   int *b=&a;
 
    cout<< a <<endl<<&a<<endl<<p<<endl<<*p<<endl<<b<<endl<<&b;*/
    
    
    double a=10.35 , b=8.35;
    int result1 =(int) a/b;
    int result3 =static_cast<int>(a)/(b);
    
    
    
    
    cout << "C-Style Cast: " << result1 << endl;
   // cout << "Function-Style Cast: " << result2 << endl;
    cout << "static_cast: " << result3 << endl;
    
    
    
    

    

	return 0;     
}