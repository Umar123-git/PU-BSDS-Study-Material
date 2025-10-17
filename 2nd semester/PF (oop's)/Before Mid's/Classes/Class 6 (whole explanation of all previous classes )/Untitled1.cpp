#include <iostream>
#include<fstream>
using namespace std;

class intclass
{
private:
    int var;

public:
	int getVar() 
	{
		 cout << "int getVar()\n";
		return var;
	}
	int getVar() const
	{
		 cout << "int getVar() const\n";
		return var;
	}
	void setVar(int &v)
	{
		var=v;
	}
	intclass(int r)
	{
		var=r;
		cout<<"intclass(int &r)  "<<var<<endl;
	}
	intclass(const intclass &ar) 
	{
		var=ar.var;
		cout<<"intclass(intclass &var)  "<<var <<endl;
	}
	intclass()
	{
		var=0;
		cout<<"intclass()  "<<this->var<<endl;
	}
	~intclass()
	{
		cout<<"~intclass()  "<<var<<endl;
	}

	intclass operator=(const intclass &rhs)
	{
		cout<<"intclass operator=(const intclass &rhs)  ";
		intclass copy;
		copy.var = rhs.var;
		return copy;
	}
	intclass operator+(const intclass &rhs)
	{
		cout<<"intclass operator+(const intclass &rhs)  ";
		intclass add(var+rhs.var);
	
		return add;
	}
	
	void disply()
	{
		cout<<"disply()  "<<this->var<<endl;
	}
	
};
		ostream & operator<<(ostream & strm, const intclass &number) // Pass by const reference
	{
	    cout << "entered ostream << operator" << endl;
	    strm << number.getVar() << endl;
	    cout << "leaving ostream << operator" << endl;
	    return strm;
	}


int main()
{
    intclass r0(10);
    intclass r1 = r0;
    intclass r2(17);
    intclass r3;

    cout << "summing" << endl;
    cout << r1 + r2 << endl;;
    cout << "summed" << endl;
    
    r3 = r3;  // Self-assignment case (handled now)
    
    return 0;
}
