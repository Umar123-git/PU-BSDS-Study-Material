#include<iostream>
#include<array>
using namespace std;

int main()
{
    int arr[10][10];
    int ar[5] = {1,2,3,4,5};

    cout<< *(ar + 3);

    int p=1;
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            arr[i][j] = p;
            cout<<p<<" ";
            p++;
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<arr[1][1];

    cout<<endl;

    cout<< *(*(arr + 1 ) + 1);

    return 0;
}