#include <iostream>
#include "time.h"

using namespace std;

int main()
{
    try
    {
        Time t1(4,30,45);
        cout << "A " << t1 << endl;
        t1.setHours(7);
        cout << "B " << t1 << endl;
        t1.setMinutes(50);
        cout << "C " << t1 << endl;
        t1.setSeconds(20);
        cout << "D " << t1 << endl;
        
        Time t2;
        t2 = t1;
        cout << "E " << t2 << endl;
        
        t2 = t1 + Time(1,15,20);
        cout << "F " << t2 << endl;
        
        cout << "Enter time as 3 integers for hour minute seconds" << endl;
        cin >> t2;
        cout << "G " << t2 << endl;
            
        return 0;
    }
    catch(const out_of_range &e)
    {
        cerr << "Out of Range error: " << e.what() << endl;
    }
}
