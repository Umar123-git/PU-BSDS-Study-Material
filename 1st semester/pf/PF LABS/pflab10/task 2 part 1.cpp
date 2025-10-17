#include <iostream>
#include <array>
using namespace std;



array<float,20>rearrangearray(array<float,20>ab,int mid)
{
	array<float,20>a;
	int i=0,j=mid+1,k=0;
	while(i<=mid && j<20)
	{
		if(ab[i]<ab[j])
		{
			a[k]=ab[i];
			i++;
		
		}
		else
		{
			a[k]=ab[j];
			j++;
			
		}
		
k++;
	}
	
	while(i<=mid)
	{
		a[k]=ab[i];
		i++;
		k++;
	}
	while(j<20)
	{
		a[k]=ab[j];
		j++;
		k++;
	}
	return a;
	
	
}


int main() {
    const int size = 20;
    int mid;
    array<float, size> arr;


    for (int i = 0; i < size; i++) {
        cout << "Enter num: ";
        cin >> arr[i];
    }
  cout<<"enter mid point:";
  cin>>mid;
 
    array<float, 20> correct = rearrangearray(arr,mid);


    cout << "Rearranged array: ";
    for (int i = 0; i < size; i++) {
        cout << correct[i] << " ";
    }
    cout << endl;

    return 0;
}