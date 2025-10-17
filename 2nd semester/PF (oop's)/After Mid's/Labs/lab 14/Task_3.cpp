#include<iostream>
#include<cmath>
#include<string>
#include<exception>

#include<iomanip>
using namespace std;

class Complex
{
    private:
        float real;
        float imag;
    public:
        Complex()
        {
            real=0.0;
            imag=0.0;
        }
        Complex(int r) 
        {
            real = r;
            imag = 0;
        }

        Complex(float r, float i)
        {
            real=r;
            imag=i;
        }
        void setreal(float r)
        {
            real=r;
        }
        void setimag(float i)
        {
            imag=i;
        }
        float getreal()
        {
            return real;
        }
        float getimag()
        {
            return imag;
        }

        friend ostream& operator<<(ostream& out, const Complex& c)
        {
            if(c.imag<0)
                out << c.real << " - " << abs(c.imag) << "i";
            else{out << c.real << " + " << c.imag << "i";}
            
            return out;
        }

};

class Rational
{
    private:
        float num;
        float den;
    public:
        Rational()
        {
            num=0.0;
            den=1.0;
        }
        Rational(int n) 
        {
            num = n;
            den = 1;
        }

        Rational(float n, float d)
        {
            num=n;
            if(d==0)
            {
                string s="Denominator cannot be zero.";
                throw s;
                return;
            }
            den=d;
        }
        void setnum(float n)
        {
            num=n;
        }
        void setden(float d)
        {
            if(d==0)
            {
                string s="Denominator cannot be zero.";
                throw s;
                return;
            }
            den=d;
        }
        float getnum()
        {
            return num;
        }
        float getden()
        {
            return den;
        }
        friend ostream& operator<<(ostream& out, const Rational& r) {
    out << r.num << "/" << r.den;
    return out;
}

};

class Vector
{
    private:
        float x;
        float y;
    public:
        Vector()
        {
            x=0.0;
            y=0.0;
        }
        Vector(int val) 
        {
            x = val;
            y = 0;
        }

        Vector(float a, float b)
        {
            x=a;
            y=b;
        }
        void setx(float a)
        {
            x=a;
        }
        void sety(float b)
        {
            y=b;
        }
        float getx()
        {
            return x;
        }
        float gety()
        {
            return y;
        }
        friend ostream& operator<<(ostream& out, const Vector& v) {
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

};



template <class T>
class matrix33
{
    protected:
        T data[3][3];
    public:
        matrix33() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            data[i][j] = T(); // or even leaving it uninitialized
}

        

        void setdata(int i, int j, T value)
        {
            if(i>=0 && i<3 && j>=0 && j<3)
                data[i][j]=value;
            else{
                string s="Index out of range.\n";
                throw s;
                return ;}
        }

        void display()
        {
            for(int i=0 ; i<3 ; i++)
            {
                for(int j=0 ; j<3 ; j++)
                {
                    cout<<data[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};


template <class T>
class null33: public matrix33<T>
{
    public:
        null33()
        {
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    this->data[i][j]=T();
                }
            }
        }
};

template <class T>
class identity33: public matrix33<T>
{
    public:
        identity33()
        {
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    if(i==j)
                        this->data[i][j]=T(1);
                    else
                        this->data[i][j]=T();
                }
            }
        }
    };


int main(){
    try
    {
    matrix33<int> intMatrix;
    intMatrix.setdata(0, 0, 1);
    intMatrix.setdata(0, 1, 2);
    intMatrix.setdata(0, 2, 3);
    cout << "Integer Matrix:" << endl;
    intMatrix.display();


    matrix33<float> floatMatrix;
    floatMatrix.setdata(1, 1, 5.5);
    cout << "\nFloat Matrix:" << endl;
    floatMatrix.display();


    matrix33<Complex> complexMatrix;
    Complex c1(1, 2);
    Complex c2(3, 4); 
    Complex c3(5, 6);
    complexMatrix.setdata(0, 0, c1);    
    complexMatrix.setdata(1, 1, c2);
    complexMatrix.setdata(2, 2, c3);
    cout << "\nComplex Number Matrix:" << endl;
    complexMatrix.display();


    matrix33<Rational> rationalMatrix;
    Rational r1(1, 2);
    Rational r2(3, 4);
    Rational r3(5, 6);
    rationalMatrix.setdata(0, 0, r1);
    rationalMatrix.setdata(1, 1, r2);
    rationalMatrix.setdata(2, 2, r3);
    cout<< "\nRational Number Matrix:" << endl;
    rationalMatrix.display();


    matrix33<Vector> vectorMatrix;
    Vector v1(1, 2);
    Vector v2(3, 4);
    Vector v3(5, 6);
    vectorMatrix.setdata(0, 0, v1);
    vectorMatrix.setdata(1, 1, v2);
    vectorMatrix.setdata(2, 2, v3);
    cout << "\nVector Matrix:" << endl;
    vectorMatrix.display();    
    


    null33<int> nullIntMatrix;
cout << "\nNull Matrix (int):" << endl;
nullIntMatrix.display();

identity33<int> identityIntMatrix;
cout << "\nIdentity Matrix (int):" << endl;
identityIntMatrix.display();

null33<Complex> nullComplexMatrix;
cout << "\nNull Matrix (Complex):" << endl;
nullComplexMatrix.display();

identity33<Complex> identityComplexMatrix;
cout << "\nIdentity Matrix (Complex):" << endl;
identityComplexMatrix.display();

    return 0;
    }









    catch(string &e)
    {
        cout << e << '\n';
    }
    
    
}