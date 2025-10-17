#include<iostream>
#include<array>
using namespace std;
array<int,5> get_subject_marks(string);
array<int,5> avg_marks(array<int,5>,array<int,5>,array<int,5>);

array<int,5> get_subject_marks(string subject){
    cout<<"Enter Five Student marks of Subject "<<subject<<" :"<<endl;
    array<int,5> marks;
    int i=0;
    while(i<5){
        cout<<"Enter Student "<<i+1<<" marks: ";
        cin>>marks[i];
        i=i+1;
    }
    return marks;
}

array<int,5> avg_marks(array<int,5> m1,array<int,5> m2 ,array<int,5> m3){
    array<int,5> average;
    int i=0;
    while(i<5){
        average[i]=(m1[i]+m2[i]+m3[i])/3;
        cout<<"STD "<<i+1<<": "<<m1[i]<<" "<<m2[i]<<" "<<m3[i]<<" = "<<average[i]<<endl;
        i=i+1;
    }
    return average;

}

int main(){
    array<int,5> PF_marks = get_subject_marks("PF");
    array<int,5> FE_marks = get_subject_marks("FE");
    array<int,5> QT_marks = get_subject_marks("QT");

    array<int,5> average = avg_marks(PF_marks,FE_marks,QT_marks);
    
    int i=0;
    while(i<5){
        cout<<"Average of Student "<<i+1<<" marks is : "<<average[i]<<endl;
        i++;
    }
    return 0;
}