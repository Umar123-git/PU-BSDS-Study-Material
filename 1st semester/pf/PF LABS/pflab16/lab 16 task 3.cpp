#include<iostream>
#include<string>
using namespace std;


void alphaDate(auto date)
{
	cout<<"enter day :";
	cin>>date->day;
	cout<<endl<<"enter month :";
	cin>>date->month;
	if(date->month<1 || date->month>12){
		cout<<"Month value can be within 1 to 12 ";
		return ;
	}
	cout<<endl<<"enter year :";
	cin>>date->year;
	
 string mon[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
 if(date->day<1 ||  date->day>31)
 {
 	cout<<"Days are invalid for the month of "<<mon[date->month-1];
 	return ;
 }
 int maxDay = 31;
    if (date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11) {
        maxDay = 30;
    }
   if (date->day < 1 || date->day > maxDay) {
        cout << "Days are invalid for the month of " << mon[date->month - 1] << "." << endl;
        return;
    }      
        
	cout<<endl<<"today date is  :"<< mon[date->month-1] <<" "<< date->day <<","<<date->year ;
   
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

    alphaDate(p);

    return 0;
}