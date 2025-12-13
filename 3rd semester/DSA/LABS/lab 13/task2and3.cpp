#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int first_non_repeating(vector<int>& v){
    vector<int> f;
    f.resize(2001);

    for(int i=0 ; i<f.size() ; i++) f[i]=0;

    for(int i=0 ; i<v.size() ; i++) f[v[i]+1000]++;

    for(int i=0 ; i<v.size() ; i++){
        if(f[v[i]+1000]==1)return v[i];
    }
    return -1;
}



void letter_in_ascending_order(string s){
    vector<pair<int,string>> freq;
    freq.resize(26);

    for(int i=0 ; i<s.length() ; i++){

        freq[i].first=0;
        
    }

    for(int i=0 ; i<s.length() ; i++){
        if(s[i]==' ')continue;
        
        int index = s[i]-65;
        freq[index].second +=s[i];
        freq[index].first++;



    }

    sort(freq.begin(),freq.end(), [](const pair<int,string>& a, const pair<int,string>& b){
        return a.first < b.first;
    });


    for(int i=0 ; i<freq.size() ; i++){
        if(freq[i].first==0)continue;
        cout<<freq[i].second;
    }

}


int main()
{
    cout<<"\n---------------Task 2--------------\n";

    vector<int> a={4,5,6,6,4,7,6,5,6,4,5,5,6};
    cout<<first_non_repeating(a);
    
    cout<<"\n---------------Task 3--------------\n";
    string s="ZXZXYYZZYYXYYZZZWWQQQQQVVVVVVVVVWXX";
    letter_in_ascending_order(s);

    
    
    return 0;
}