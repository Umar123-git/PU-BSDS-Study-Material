#include<iostream>
#include<algorithm>
#include<string>
using namespace std;



bool isGoodNumber(const string &s, int index=0)
{
    bool t = false;
    if(index==s.length())return true;
    else if(index%2==0){
        if((s[index]-'0')%2==0) t = true;
        //else t = false;
    }
    else if(index%2==1){
        if((s[index]-'0')==1 || (s[index]-'0')==2 || (s[index]-'0')==3 ||
          (s[index]-'0')==5 || (s[index]-'0')==7){
                t=true;
          }
          //else t = false;
    }

    return (t==true)? isGoodNumber(s,index + 1) : false;

}

int main()
{
    string digit_strings[]={"02468","23478","224365"};
    
    for(string digits : digit_strings){
        bool is_good = isGoodNumber(digits,0);
        cout<<"Digit string : "<<digits<<" is "<<(is_good ? "good" : "not good")<<endl;
    }

    return 0;
}