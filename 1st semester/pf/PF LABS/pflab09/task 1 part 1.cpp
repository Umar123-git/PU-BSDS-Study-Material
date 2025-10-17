#include<iostream>
#include<string>
#include<cmath>
using namespace std;


void monthsname(string months[], int size)
{
	int i=0;
	while(i<size)
	{
		cout << months[i] << endl;
		i++;
	}
	
	
	
	
	

}


int main()
{
	
	string months [12];
	
	
	months[0] = "june";
	months[1] = "july";
	months[2] = "august";
	months[3] = "october";
	months[4] = "december";
	months[5] = "january";
	months[6] = "may";
	months[7] = "febrary";
	months[8] = "april";
	months[9] = "november";
	months[10]= "march";
	months[11]= "september";
	
	
	
	monthsname(months,12);
	
	
	
	return 0;
}
