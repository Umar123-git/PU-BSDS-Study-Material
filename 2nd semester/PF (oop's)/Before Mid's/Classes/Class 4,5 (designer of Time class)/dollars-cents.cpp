#include <iostream>
#include <math.h>

using namespace std;

class Cents
{
private:
	int m_cents;
public:
 	int getCents() const 
	{ 
		return m_cents; 
	}
	void setCents(int cents) 
	{ 
		m_cents = cents; 
	}
	Cents(int cents = 0)
	{
		m_cents = cents;
	}
 
	// Overloaded int cast
	operator int() const 
	{ 
		return m_cents; 
	}
};
 
class Dollars
{
private:
    int m_dollars;
public:
    Dollars(int dollars=0)
    {
        m_dollars = dollars;
    }
 
	// Overloaded int cast
	operator int() const 
	{ 
		return m_dollars; 
	}

	// Overloaded Dollar cast
    // Allow us to convert Cents into Dollars
    Dollars(Cents cents)
    {
        m_dollars = Dollars(int(cents) / 100);
    }
 
	// Overloaded Cents cast
    // Allow us to convert Dollars into Cents
    operator Cents() const 
	{
		return Cents(m_dollars * 100);
	}
};
 
void printDollars(Dollars dollars)
{
    cout << dollars; // cents will be implicitly cast to an int here
}
 
void printCents(Cents cents)
{
    cout << cents; // cents will be implicitly cast to an int here
}
 
int main()
{
    Dollars dollars(9);
    printCents(dollars); // dollars will be implicitly cast to a Cents here
    cout << endl;

    Cents cents(1900);
    printDollars(cents); // cents will be implicitly cast to a Cents here
    cout << endl;
    return 0;
}
