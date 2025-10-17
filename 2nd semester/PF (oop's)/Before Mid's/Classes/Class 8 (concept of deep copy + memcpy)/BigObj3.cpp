
// comment the call log (first) line of each function

#include <iostream>
#include <cstring>

using namespace std;

class BigObj {
public:
    ~BigObj() {
        cout << "destructor" << endl;
        delete [] m_arr;
        m_arr = nullptr;
    }
    BigObj(int sz) {
        cout << "parameterised constructor" << endl;
        m_arr = new int [sz];
        for (int i=0; i < sz; ++i) {
            m_arr[i] = i;
        }
        m_size = sz;
    }
    BigObj(const BigObj& other) {
        cout << "copy constructor" << endl;
        m_arr = new int[other.m_size];
        memcpy(m_arr, other.m_arr, other.m_size*sizeof(int));
        m_size = other.m_size;
    }
    
    BigObj(BigObj&& other) {
        cout << "move constructor" << endl;
        m_arr = other.m_arr;
        m_size = other.m_size;
        other.m_arr = nullptr;
        other.m_size = 0;
    }
    
    BigObj operator=(BigObj& other) {
        cout << "copy assignment" << endl;
        if (this != &other){
            delete [] m_arr;
            m_arr = new int[other.m_size];
            memcpy(m_arr, other.m_arr, other.m_size*sizeof(int));
            m_size = other.m_size;
        }
        return (*this);
    }
    
    BigObj operator=(BigObj&& other) {
        cout << "move assignment" << endl;
        if (this != &other){
            delete [] m_arr;
            m_arr = other.m_arr;
            m_size = other.m_size;
            other.m_arr = nullptr;
        }
        return (*this);
    }
    

    void double_elem() {
        cout << "void double_elem()" << endl;
        for (int i = 0; i < m_size; ++i) {
            m_arr[i] *= 2;
        }
    }
    void display() {
        cout << "void display()" << endl;
        for (int i = 0; i < m_size; ++i) {
            cout << m_arr[i] << " ";
        }
        cout << endl;
    }
private:
    int *m_arr;
    int m_size;

};

BigObj create_big_obj(int sz)
{
    cout << "GLOBAL BigObj create_big_obj(int sz)" << endl;
    BigObj b(sz);
    return b;
}

void make_double(BigObj b) {
    cout << "GLOBAL void make_double(BigObj b)" << endl;
    b.double_elem();
    b.display();
}

int main() {
    try
    {
        cout << "---------------0" << endl;
        BigObj b(10);
        cout << "---------------1" << endl;
        make_double(b);
        cout << "---------------2" << endl;
        make_double(create_big_obj(10));
        cout << "===============3" << endl;

        BigObj k(10);
        cout << "---------------4" << endl;
        k = b;
        k.display();
        cout << "---------------5" << endl;
        k = create_big_obj(10);
        k.display();
        cout << "---------------6" << endl;
    }
    catch(...)
    {
        cerr << "A runtime exception occured" << endl;
    }

    return 0;
}