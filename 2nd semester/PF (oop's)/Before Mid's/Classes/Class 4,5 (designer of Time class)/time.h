#ifndef my_time_class_00227772
#define my_time_class_00227772

#include <iostream>
#include <stdexcept>

using namespace std;

// represents current clock time
class Time
{
    protected:
        // the ticks count since midnight 00:00:00
        // each tick is a second
        int ticks;
        
        // private constructor
        explicit Time(int tks);

        
    public:
        // set the seconds of time object
         void setSeconds(int s);
        // set the minutes of time object
         void setMinutes(int m);
        // set the hours of time object
         void setHours(int h);

        // get the seconds of time object
         int getSeconds() const;
        // get the minutes of time object
         int getMinutes() const;
        // get the hours of time object
         int getHours() const;
        
        // default constructor
        Time();
        
        // natural constructor
        Time(int h, int m, int s);
        
        // to add a time to another time object
        Time operator+(const Time &rhs) const;
};

// global functions
ostream & operator<<(ostream & ostrm, const Time &rhs);
istream & operator>>(istream & istrm, Time &rhs);

#endif