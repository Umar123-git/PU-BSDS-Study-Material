#include<iostream>
#include<string>
using namespace std;

void main_function(auto date);


void alphaDate(int day, int month, int year) {
    if (month < 1 || month > 12) {
        cout << "Month value must be within 1 to 12." << endl;
        return;
    }


    string mon[12] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};


    if (day < 1 || day > 31) {
        cout << "Days are invalid for the month of " << mon[month - 1] << "." << endl;
        return;
    }


    int maxDay = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDay = 30;
    } else if (month == 2) {
  
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        maxDay = isLeapYear ? 29 : 28;
    }


    if (day < 1 || day > maxDay) {
        cout << "Days are invalid for the month of " << mon[month - 1] << "." << endl;
        return;
    }


    cout << "Today date is: " << mon[month - 1] << " " << day << ", " << year << "." << endl;
}



struct Date{
	int day;
	int month;
	int year;
};

int main() 
{
    Date date;
    auto *p = &date;

 //   alphaDate(p);
main_function(p);
    return 0;
}

void main_function(auto date)
{
	cout<<"enter day :";
	cin>>date->day;
	cout<<endl<<"enter month :";
	cin>>date->month;
	cout<<endl<<"enter year :";
	cin>>date->year;
	
	alphaDate(date->day , date->month , date->year);
	
}