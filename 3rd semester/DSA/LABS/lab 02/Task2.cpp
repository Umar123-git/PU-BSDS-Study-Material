#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class NDArray {
private:
    vector<int> dimensions;
    vector<T> data;
    int size;

public:
    NDArray(int s, int arr[]) 
    {
        size = s;
        int totalSize = 1;
        for (int i = 0; i < size; ++i) 
        {
            dimensions.push_back(arr[i]);
            totalSize *= arr[i];
        }
        data.resize(totalSize);
    }

    int calculateIndex(int indexset[]) const 
    {
        int index = 0;
        int p = 1;
        for (int i = size - 1; i >= 0; --i) 
        {
            index += indexset[i] * p;
            //index += p
            p *= dimensions[i];
        }
        return index;
    }

    void setValue(int indexset[], const T& value) 
    {
        int index = calculateIndex(indexset);
        if (index >= 0 && index < data.size()) 
        {
            data[index] = value;
        }
    }

    T getValue(int indexset[]) const 
    {
        int index = calculateIndex(indexset);
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
