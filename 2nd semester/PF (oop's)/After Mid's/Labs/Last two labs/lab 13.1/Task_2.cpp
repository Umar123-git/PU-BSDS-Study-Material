#include<iostream>
#include<array>
using namespace std;

class task_3
{
    private:
        float* arr;
        float avg;
    public:
        task_3(int s, float ar[])
        {
            arr = new float[s];
            for(int i=0 ; i<s ; i++)
            {
                arr[i] = ar[i];
            }

            avg = 0.0;
        }
        
        ~task_3()
        {
            delete[] arr;
        }
        
        void sorting()
        {
            for(int i=0 ; i<10 ; i++)
            {
                for(int j=i+1 ; j<10 ; j++)
                {
                    if(arr[i] > arr[j])
                    {
                        float temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
           // return 0;
        }

        void average(int s) 
        {
            float sum = 0 ;
            for(int i=0 ; i<10 ; i++)
            {
                sum=arr[i] + sum;
            }
            avg = sum / s;
            
        }

        void display()
        {
            cout<<"Sorted Array is : ";
            for(int i=0 ; i<10 ; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<"Average of the array elements is : "<<avg<<endl;
        }

        
};





int main()
{
    float arr1[10] = {3.2, 7.8, 1.5, 9.0, 4.6, 2.1, 8.3, 5.7, 6.4, 0.9};
    task_3 s(10, arr1);
    s.sorting();
    
    s.average(10);
    s.display();




    return 0;
}