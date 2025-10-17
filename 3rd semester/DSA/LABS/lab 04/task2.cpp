#include"Stack.h"
#include <iostream>
using namespace std;

    class word
    {
        private:
            Stack<char> st;
            string s;
        public:
            word()
            {

            }
            word(string h)
            {
                s=h;
                st = Stack<char>(s.length());
            }

            string reverse()
            {
                if(s.length()==0)throw runtime_error("String is empty");
                string rev="";
                for(int i=0 ; i<s.length() ; i++)
                {
                    if(s[i]==' ')
                    {
                        while(!st.isempty()){
                            rev+=st.pop();
                        }
                        rev+=s[i];
                    }else{
                        st.push(s[i]);
                    }
                }
                if(!st.isempty()){
                    while(!st.isempty()){
                            rev+=st.pop();
                        }
                }

                return rev;
            }

    };

int main()
{
    
    string p="qwerty dfgh hvj";
    word w(p);
    cout<<w.reverse();

    
    return 0;
}