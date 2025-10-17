#include <iostream>
using namespace std;
int main()
{
	int **arr = new int*[3];
	for (int i = 0;i<3;i++)
	 { arr[i]= new int[3];
}

	 for (int i = 0;i<3;i++)
	 {
	 	
	 
	 for (int j = 0;j<3;j++)
	 {
	 	cin>>arr[i][j];
	 }  

}  
 for (int i = 0;i<3;i++)
	 {
	 	
	 
	 for (int j = 0;j<3;j++)
	 {
	 	cout<<arr[i][j]<<" ";
	 }  
	 cout<<endl;
}  
	  delete [ ]arr;
	  delete[] *arr;
	  return 0;
}