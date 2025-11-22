#include <iostream>
#include<string>
using namespace std;



class HashTable{
    private:
        string* table;
        int s;
        int n;

    public:
        HashTable(int size){
            s=size;
            table = new string[s];
            n=0;
        }

        ~HashTable(){
            delete[] table;
        }

        bool isFull(){
            return n==s;
        }
         
        bool isEmpty(){
            return n==0;
        }

        double loadFactor(){
            return (double)n/s;
        }

        int getHashValue(string name){
            int hash = 0;
            for(char ch : name){
                hash += ch;
            }
            return hash % s;
        }

        bool insert(string name){
            if(isFull()){
                return false;
            }
            int index = getHashValue(name);
            while(!table[index].empty()){
                index = (index + 1) % s;
            }
            table[index] = name;
            n++;
            return true;
        }

        bool search(string name){
            if(isEmpty()){
                return false;
            }
            int index = getHashValue(name);
            int startIndex = index;
            while(!table[index].empty()){
                if(table[index] == name){
                    return true;
                }
                index = (index + 1) % s;
                if(index == startIndex){
                    break;
                }
            }
            return false;
        }

        bool remove(string name){
            if(isEmpty()){
                return false;
            }
            int index = getHashValue(name);
            int startIndex = index;
            while(!table[index].empty()){
                if(table[index] == name){
                    table[index].clear();
                    n--;
                    return true;
                }
                index = (index + 1) % s;
                if(index == startIndex){
                    break;
                }
            }
            return false;
        }


        void display(){
            for(int i=0; i<s; i++){
                if(!table[i].empty()){
                    cout << i << ": " << table[i] << endl;
                } else {
                    cout << i << ": " << "EMPTY" << endl;
                }
            }
        }


};




int main()
{
    HashTable ht(10);
    ht.insert("Alice");
    ht.insert("Bob");
    ht.insert("Charlie");
    ht.display();
    cout << (ht.search("Bob") ? "Found" : "Not Found") << endl;
    ht.remove("Bob");
    ht.display();
    cout<<ht.loadFactor();

    return 0;
}