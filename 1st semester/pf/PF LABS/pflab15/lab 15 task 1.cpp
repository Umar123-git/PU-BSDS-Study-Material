#include<iostream>
#include<string>
using namespace std;




struct Teacher
{
	string name;
	string course;
	string department;
	int rank;
};


int main()
{ 
	int size;
	cout<<"enter no. of teachers :";
	cin>>size;
	Teacher *teachers = new Teacher[size];
	for (int i = 0; i <size ; i++) {
        cout << "Enter data for Teacher " << (i + 1) << ":" << endl;
        cin.ignore();
        cout << "Name: ";
        getline(cin,teachers[i].name);
        cout << "Course: ";
        getline(cin,teachers[i].course);
        cout << "Department: ";
        getline(cin,teachers[i].department);
        cout << "Rank: ";
        cin >> teachers[i].rank;
     
    }
	
	

	
	cout << "Sr. No   Name        Course       Department     Rank"<<endl;
	 for (int i = 0; i <size ; i++) {
        cout << (i + 1) << "        "<< teachers[i].name << "        "<< teachers[i].course << "        "<< teachers[i].department << "        " << teachers[i].rank << endl;
    }

	 delete[] teachers;
	
	return 0;
}