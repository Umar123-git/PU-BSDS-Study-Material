
#include<algorithm>
#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;

class infix
{
    private:
        string s;
        Stack<char> st;
    public:
        infix(string a)
        {
            s=a;
            st = Stack<char>(s.size());
        }
/*
        int getprecidence(char a)
        {
            if (a == '*' || a == '/')
                return 2;
            if (a == '+' || a == '-')
                return 1;
            if (a == '{' || a == '(' || a == '[')
                return 0;
            return -1;
        }

        bool presidence(char a)
        {
            char b = st.peek();   // top operator from stack
            int pa = getprecidence(a);  // precedence of new operator
            int pb = getprecidence(b);  // precedence of operator in stack

            if (pa == -1 && pb == -1)
            {
                throw invalid_argument("Invalid expression");
            }

            return pb >= pa;  // true if stack top has higher or equal precedence
        }*/


        bool presidence(char a)
        {
            char b = st.peek();
            if(a=='(' || a=='{' || a=='[')return false;
            if(a=='/' && b=='*')return true;
            if((a=='/') && (b=='*' || b=='+' ||b=='-'))return false;
            if((a=='*') && (b=='+' || b=='-'))return false;
            if(a=='+' && b=='-')return false;
            return true;
        }
/*
        bool presidence(char a)
        {
            char b = st.peek();
            if (a=='(' || a=='{' || a=='[') return false;

            int pa = (a=='+'||a=='-') ? 1 : (a=='*'||a=='/') ? 2 : 0;
            int pb = (b=='+'||b=='-') ? 1 : (b=='*'||b=='/') ? 2 : 0;
            return pb >= pa;
        }

*/
        void postfix()
        {
            //if(s.size()==0)cout<<"String is empty";return ;
            string r="";
            string s1=s;
            for(int i=0 ; i<s1.size() ; i++)
            {
                cout << "\nReading: " << s1[i] << endl;
                if(s1[i]=='+' || s1[i]=='-' || s1[i]=='*' || s1[i]=='/' ||
                   s1[i]=='(' || s1[i]==')' || s1[i]=='{' || s1[i]=='}' ||
                   s1[i]=='[' || s1[i]==']')
                   {
                        while(!st.isempty() && presidence(s1[i]) && st.peek()!='(' && st.peek()!='{' && st.peek()!='[')
                        {
                            r+=st.pop();
                            cout<<"\nwhile loop: \n";
                        }
                        if(s1[i]==')' || s1[i]=='}' || s1[i]==']')
                        {
                            char c;
                            if(s1[i]==')')
                                c='(';
                            else if(s1[i]=='}')
                                c='{';
                            else
                                c='[';
                            while(!st.isempty() && st.peek()!=c)
                            {
                                r+=st.pop();
                            }
                            if(!st.isempty()){
                                st.pop();}
                        }else{
                            st.push(s1[i]);
                        }

                   }else{
                        r+=s1[i];
                   }
                    cout << "Current result: " << r << endl;
                    cout << "Stack top (if any): ";
                    if(!st.isempty()) cout << st.peek() << endl;
                    else cout << "(empty)" << endl;
            }
            while(!st.isempty())
            {
                r+=st.pop();
            }
            s=r;
            cout << "\nFinal postfix: " << s << endl;
        }

        void prefix()
        {
            //if(s.length()==0)cout<<"String is empty";return ;
            cout<<endl<<s;
            reverse(s.begin(),s.end());
            cout<<endl<<s;
            for(int i=0 ; i<s.length() ; i++)
            {
                if(s[i]=='(')s[i]=')';
                else if(s[i]==')')s[i]='(';
                else if(s[i]=='{')s[i]='}';
                else if(s[i]=='}')s[i]='{';
                else if(s[i]=='[')s[i]=']';
                else if(s[i]==']')s[i]='[';
            }
            cout<<endl<<s;
            postfix();
            reverse(s.begin(),s.end());
            cout<<endl<<s;
            return ;
        }

        double calculatepost()
        {
            double ans;
            st = Stack<char>(s.size());
            for(int i=0 ; i<s.size() ; i++)
            {
                if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                {
                    float t1 = st.pop();
                    float t2 = st.pop();
                    cout<<"t1 = "<<t1<<" t2 = "<<t2;
                    float t3=0;
                    if(s[i]=='+')t3=t1+t2;
                    else if(s[i]=='-')t3=t2-t1;
                    else if(s[i]=='*')t3=t1*t2;
                    else t3=t2/t1;
                    cout<<" t3 = "<<t3<<endl;
                    st.push(t3);
                }else{
                    st.push(s[i]-48);
                }
                //cout<<st.peek()<<" ";
                
            }

            ans = st.peek();
            return ans;

        }
        double calculatepre()
        {
            reverse(s.begin(),s.end());
            double ans;
            st = Stack<char>(s.size());
            for(int i=0 ; i<s.size() ; i++)
            {
                if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                {
                    float t1 = st.pop();
                    float t2 = st.pop();
                    cout<<"t1 = "<<t1<<" t2 = "<<t2;
                    float t3=0;
                    if(s[i]=='+')t3=t1+t2;
                    else if(s[i]=='-')t3=t1-t2;
                    else if(s[i]=='*')t3=t1*t2;
                    else t3=t2/t1;
                    cout<<" t3 = "<<t3<<endl;
                    st.push(t3);
                }else{
                    st.push(s[i]-48);
                }
            }
                ans = st.peek();
            return ans;
            
        }

};

int main()
{
    //string o="5+2*(3+1)-6/4";
    string o="(4+8)*(6-5)/((3-2)*(2+2))";
    //string o="(4+8)*(6-5)/((3-2)*(2+2))";
    //string o="a+b*(c+d)-f/g";
    //string o="a+(b*c/(e-f))";
    infix x(o);
    x.postfix();
    //x.prefix();
    cout<<endl;
    cout<<x.calculatepost();

    
}
