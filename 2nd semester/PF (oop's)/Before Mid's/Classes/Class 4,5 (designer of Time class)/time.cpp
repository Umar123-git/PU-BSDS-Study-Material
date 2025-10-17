#include <iostream>
#include "time.h"

using namespace std;

inline void Time::setSeconds(int s)
{
    int h = this->getHours();
    int m = this->getMinutes();
    *this = Time(h,m,s);
}
void Time::setMinutes(int m)
{
    int h = this->getHours();
    int s = this->getSeconds();
    *this = Time(h,m,s);
}
void Time :: setHours(int h)
{
    int m = this->getMinutes();
    int s = this->getSeconds();
    *this = Time(h,m,s);
}

int Time::getSeconds() const
{
    return (this->ticks - this->getHours()*60*60 - this->getMinutes()*60);
}

int Time::getMinutes() const
{
    return (this->ticks - this->getHours()*60*60) / 60;
}

int Time::getHours() const
{
    return (this->ticks / (60*60));
}

Time::Time(int tks)
{
    this->ticks = tks;
}

Time::Time()
{
    this->ticks = 0;
}

Time::Time(int h, int m, int s)
{
    if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >=0 && s <= 59)
    {
        this->ticks = h * 60 * 60 + m * 60 + s;
    }
    else
    {
        throw out_of_range("out of range values in arguments"); 
    }
}

Time Time::operator+(const Time &rhs) const
{
    return Time((this->ticks + rhs.ticks) % (24*60*60));
}

// output a time object in hh:mm:ss format
ostream & operator<<(ostream & ostrm, const Time &rhs)
{
    ostrm << rhs.getHours() << ':' << rhs.getMinutes() << ':' << rhs.getSeconds();
    return ostrm;
}

// input a time object in (hh mm ss) format, without ()
istream & operator>>(istream & istrm, Time &rhs)
{
    int h, m, s;
    istrm >> h >> m >> s;
    rhs.setHours(h);
    rhs.setMinutes(m);
    rhs.setSeconds(s);
    return istrm;
}

