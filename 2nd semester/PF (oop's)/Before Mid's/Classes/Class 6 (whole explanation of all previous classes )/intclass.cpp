#include <iostream>
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
            intclass() : var(0)  // Initialize to avoid garbage value
    {
        cout << "intclass() " << var << endl;
    }
        void setVar(int v)
        {
            cout << "void setVar(int v) " << var << endl;
            var = v;
        }
      /*  intclass()
        {
            cout << "intclass() " << var << endl;
        }*/
        intclass(int v) 
        {
            cout << "intclass(int v) " << v << endl;
            var = v;
        }
		intclass(intclass &r) 
        {
            cout << "intclass(intclass &r) " << r.var << endl;
            var = r.var;
        }
        /*
        intclass(const intclass &r)
        {
            cout << "intclass(const intclass &r) " << r.var << endl;
            var = r.var;
        }
        */
        ~intclass()
        {
            cout << "~intclass() "  << var << endl;
        }
        void display()
        {
            cout << "void display() "  << var << endl;
            cout << var ;
        }
        //intclass operator=(intclass rhs)
		intclass & operator=(const intclass & rhs)
        {
            cout << "entered in assignment operator" << endl;
            var = rhs.var;
            cout << "leaving assignment operator" << endl;
            return *this;
        }
        //intclass operator+(intclass rhs)
         intclass operator+(const intclass &rhs) const // Pass by const reference
    {
        cout << "entered in plus operator" << endl;
        // intclass res;
        //   res.var = var + rhs.var;
        intclass res(var + rhs.var);
        cout << "leaving plus operator" << endl;
        return res;
    }
};

//ostream & operator<<(ostream & strm, intclass number)
ostream & operator<<(ostream & strm, const intclass &number) // Pass by const reference
{
    cout << "entered ostream << operator" << endl;
    strm << number.getVar() << endl;
    cout << "leaving ostream << operator" << endl;
    return strm;
}


int main(void)
{
    intclass r0(10);
    intclass r1 = r0;
    intclass r2 = intclass(17);
    intclass r3;
    cout << "summing" << endl;
    cout << r1 + r2 << endl;
    cout << "summed" << endl;
    r3 = r3;

    return 0;
}
/*
intclass(int v) 10
intclass(intclass &r) 10
intclass(int v) 17
intclass() 0
summing
entered in plus operator
intclass(int v) 27
leaving plus operator
entered ostream << operator
int getVar() const
27
leaving ostream << operator

~intclass() 27
summed
entered in assignment operator
leaving assignment operator
~intclass() 0
~intclass() 17
~intclass() 10
~intclass() 10
*/
