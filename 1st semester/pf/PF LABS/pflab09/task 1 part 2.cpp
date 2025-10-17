#include <iostream>
#include <cctype>
using namespace std;


void countCategories(char arr[], int size) {
    int alphabets = 0, digits = 0, specialSigns = 0;
    int i=0;
    while ( i < size) 
	{
        if (isalpha(arr[i]))
		 {
            alphabets++;
        } 
		else if (isdigit(arr[i]))
		 {
            digits++;
        } 
		else 
		{
            specialSigns++;
        }
        i++;
    }

    cout << "Alphabets: " << alphabets << endl;
    cout << "Digits: " << digits << endl;
    cout << "Special Signs: " << specialSigns << endl;
}

int main() {
  
    char arr[20] = {'a', '1', '@', 'B', '2', '#', 'c', '3', '$', 'D', '4', '%', 'e', '5', '^', 'F', '6', '&', 'g', '7'};

 
    countCategories(arr, 20);

    return 0;
}
