#include<iostream>
#include<array>
using namespace std;


int main()
{
	double *v[25];
	for(int i=0 ; i<25 ; i++)
	{
		v[i]=new double[i+1];
	
	}
	
	for(int i=0 ; i<25 ; i++){
		for(int j=0 ; j<i+1 ; j++){
			v[i][j]=2+rand() %8;
		}
	}
	
	
 for (int i = 0; i < 25; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl; 
    }
    
    
    for(int i=0 ; i<25 ; i++){
	delete[]v[i];
	}

	return 0;
}