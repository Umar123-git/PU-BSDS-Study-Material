#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class NDArray
{
    private:
        vector<int> dimentions;
        vector<T> data;
        int size;
    public:
        NDArray(int s, int arr[])
        {
            size=s;
            int t=1;
            for(int i=0 ; i<s ; i++)
            {
                dimentions.push_back(arr[i]);
                t*=arr[i];
            }
            data.resize(t);
        }

        int calculateIndex(int arr[])const
        {
            int indx=0;
            int p;
            for(int i=0 ; i<dimentions.size() ; i++)
            {
                p=arr[i];
                for(int j=i+1 ; j<dimentions.size() ; j++)
                {
                    p = p *  dimentions[j];
                }
                indx += p;
            }
            return indx;
        }

        void setValue(int arr[],const T& val)
        {
            int index = calculateIndex(arr);
            if (index >= 0 && index < data.size()) 
            {
                data[index] = val;
            }
        }

        T getValue(int arr[])const
        {
            int index = calculateIndex(arr);
            if (index >= 0 && index < data.size()) 
            {
                return data[index];
            }
            throw out_of_range("Index out of range");
        }

};
int main() 
{
    
    int dimsize[3]={5,3,10};
    NDArray<int> arr(3,dimsize);

    int indexset[3]={4,2,8};
    cout<<arr.calculateIndex(indexset)<<endl;

    int val=100;

    arr.setValue(indexset,val);

    cout<<arr.getValue(indexset);



    return 0;
}