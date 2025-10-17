#include<iostream>
#include<vector>
#include<algorithm>
#include"Stack.h"
using namespace std;

class Palindrome
{
private:
    string s;
    Stack<char> st;

public:
    Palindrome(string a)
    {
        s = a;
        st = Stack<char>(s.length());
    }

    bool isPalindrome()
    {
        vector<char> v;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ') continue;
            else {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = s[i] + 32;
                }
                v.push_back(s[i]);
            }
        }

        int j = 0;
        if (v.size() % 2 == 0) j = v.size() / 2 - 1;
        else j = v.size() / 2;

        for (int i = 0; i < j; i++)
        {
            st.push(v[i]); 
        }

        int i = 0;
        cout << v.size() << endl;
        if (v.size() % 2 == 0) i = v.size() / 2;
        else i = (v.size() / 2) + 1;

        while (!st.isempty())
        {
            cout << "\nst = " << st.peek() << " v[" << i << "] = " << v[i]; 
            if (st.peek() != v[i]) {
                cout << "\n" << s << " is not a palindrome\n";
                return false;
            }
            else {
                st.pop();
                i++;
            }
        }
        cout << "\n" << s << " is a palindrome\n";
        return true;
    }

    bool checkTask2()
    {
        if (s.length() % 2 == 1 || s[0] == 'B' || s[0] == 'b') {
            cout << s << " -- is not of the form anbn\n";
            return false;
        }
        //st = Stack<char>(s.length());
        Stack<char> stA(s.length() / 2);
        Stack<char> stB(s.length() / 2);

        for (int i = 0; i < s.length() / 2; i++)
        {
            stA.push(s[i]);
        }

        for (int i = s.length() / 2; i < s.length(); i++)
        {
            stB.push(s[i]);
        }

        while (!stA.isempty() && !stB.isempty())
        {
            char a = stA.pop();
            char b = stB.pop();
            if (tolower(a) != 'a' || tolower(b) != 'b') {
                cout << s << " -- is not of the form anbn\n";
                return false;
            }
        }

        cout << s << " -- is of the form anbn\n";
        return true;
    }

    bool isValid()
    {
        Stack<char> tempStack(s.length());

        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[') {
                tempStack.push(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                if (tempStack.isempty()) return false;
                if ((c == ')' && tempStack.peek() != '(') ||
                    (c == '}' && tempStack.peek() != '{') ||
                    (c == ']' && tempStack.peek() != '[')) {
                    return false;
                }
                tempStack.pop();
            }
        }

        return tempStack.isempty();
    }

    string add(string a, string b)
    {
        Stack<int> s1(a.length());
        Stack<int> s2(b.length());
        Stack<int> resultStack(a.length() + b.length());
        string str = "";
        int c = 0;

        for(int i = 0; i < a.length(); i++)
        {
            s1.push(a[i] - '0');
        }
        for(int i = 0; i < b.length(); i++)
        {
            s2.push(b[i] - '0');
        }

        while(!s1.isempty() || !s2.isempty() || c > 0)
        {
            int sum = c;
            if(!s1.isempty()) sum += s1.pop();
            if(!s2.isempty()) sum += s2.pop();

            c = sum / 10;
            sum = sum % 10;

            resultStack.push(sum + '0');
        }

        while(!resultStack.isempty())
        {
            str += resultStack.pop();
        }

        reverse(str.begin(), str.end());
        return str;
    }

};

int main()
{
    string pal1 = "Racecar";
    string pal2 = "Too bad I hid a boot";
    Palindrome p1(pal1);
    cout << "\nChecking Palindrome for: " << pal1 << endl;
    cout << "Result: " << p1.isPalindrome() << endl;

    Palindrome p2(pal2);
    cout << "\nChecking Palindrome for: " << pal2 << endl;
    cout << "Result: " << p2.isPalindrome() << endl;

    string ab1 = "aaabbb";
    string ab2 = "ababab";
    string ab3 = "bbbaaa";
    Palindrome p3(ab1);
    cout << "\nChecking anbn for: " << ab1 << endl;
    cout << "Result: " << p3.checkTask2() << endl;

    Palindrome p4(ab2);
    cout << "\nChecking anbn for: " << ab2 << endl;
    cout << "Result: " << p4.checkTask2() << endl;

    Palindrome p5(ab3);
    cout << "\nChecking anbn for: " << ab3 << endl;
    cout << "Result: " << p5.checkTask2() << endl;

    string expr1 = "(5+)";
    string expr2 = "((3+2)*[4-1])";
    string expr3 = "([)]";
    Palindrome p6(expr1);
    cout << "\nChecking validity for: " << expr1 << endl;
    cout << "Result: " << p6.isValid() << endl;

    Palindrome p7(expr2);
    cout << "\nChecking validity for: " << expr2 << endl;
    cout << "Result: " << p7.isValid() << endl;

    Palindrome p8(expr3);
    cout << "\nChecking validity for: " << expr3 << endl;
    cout << "Result: " << p8.isValid() << endl;

    string num1 = "56787";
    string num2 = "3784";
    Palindrome p9("");
    cout << "\nAdding large numbers: " << num1 << " + " << num2 << endl;
    cout << "Sum: " << p9.add(num1, num2) << endl;

    return 0;
}
