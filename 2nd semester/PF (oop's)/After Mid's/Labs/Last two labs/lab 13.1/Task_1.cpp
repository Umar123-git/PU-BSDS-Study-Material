#include<iostream>
using namespace std;

class val
{
    private:
        int val1;
        int val2;
        int* myPointer;
    public:
     val()
     {
        val1 = 23;
        val2 = 0;
     }

     int getval1()
     {
        return val1;
     }
     int getval2()
     {
        return val2;
     }

     void a()
     {
      cout<<"------------------A--------------------------"<<endl;
         cout<<"addreess of val1 is : "<<&val1<<endl;
         cout<<"addreess of val2 is : "<<&val2<<endl;
     }
     void c()
     {
      cout<<"------------------C--------------------------"<<endl;
      cout<<"size of myPointer in bytes : "<<sizeof(myPointer)<<endl;
     }
     void d()
     {
      cout<<"------------------D--------------------------"<<endl;
      cout<<"address of myPointer is : "<<myPointer<<endl;
      cout<<"adress of val1 is : "<<&val1<<endl;
      myPointer = &val1;
      cout<<"assigning address of val1 to myPointer : "<<myPointer<<endl;
     }

     void e()
     {
      cout<<"------------------E--------------------------"<<endl;
         cout<<"value of myPointer is : "<<*myPointer<<endl;
     }

     void f()
     {
      cout<<"------------------F--------------------------"<<endl;
      cout<<"value of val2 is : "<<val2<<endl;
      cout<<"value of myPointer is : "<<*myPointer<<endl;
      val2 = *myPointer;
      //cout<<"--------------------------------------------"<<endl;
     }
     void g()
     {
      cout<<"------------------G--------------------------"<<endl;
      cout<<"Assigning the value of the object pointed to by myPointer to variable val2 : "<<val2<<endl;
     }

     void h()
     {
      cout<<"------------------H--------------------------"<<endl;
      cout<<"address of myPointer is : "<<myPointer<<endl;
     }

     void i()
     {
      cout<<"------------------I--------------------------"<<endl;
      cout<<"Indirectly print the value of myPointer : "<<val1<<endl;
     }

     void j()
     {
      cout<<"------------------J--------------------------"<<endl;
      myPointer = NULL;
      cout<<"Storing NULL in myPointer and indirectly print the value of myPointer : "<<val1<<endl;
      
     }

     void display()
     {
         cout<<"--------------------------------------------"<<endl;
        cout<<val1<<endl;
        cout<<val2<<endl;
     }
};

int main()
{
    val v;
   v.a();
   v.c();
   v.d();
   v.e();
   v.f();
   v.g();
   v.h();
   v.i();
   v.j();
    //v.display();

    




    return 0;
}