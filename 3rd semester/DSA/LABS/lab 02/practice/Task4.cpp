#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<stdio.h>
#include<windows.h>
using namespace std;


struct Student
{
    int roll;
    char name[30];
    Student(): roll(0)
    {
        strcpy(name,"nome");
    }
};


    void addToStudentUnBuffered(int N) 
    { 
        ofstream  ofs("studentdatabase.txt",ios::binary|ios::out); 
        Student s; 
        for (int i=1; i<N; i++) 
        { 
            s.roll = i; 
            ofs.write((char*)(&s),sizeof(Student)); 
        } 
        ofs.close(); 
}

    void data()
    {
        fstream open("studentdatabase.txt", ios::in);
        string s;
        while(getline(open,s))
        {
            //open >> s;
            cout<<s<<endl;
        }
    }

int main()
{
    SYSTEMTIME systime;  
    cout<<"\nWriting Records to File one by one";  
    GetLocalTime(&systime);  
    cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
  
    addToStudentUnBuffered(100);  
    GetLocalTime(&systime);  
    cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;

    data();

    return 0;
}