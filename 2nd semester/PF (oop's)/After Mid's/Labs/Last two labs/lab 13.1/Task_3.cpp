#include<iostream>
#include<array>
using namespace std;

class Triangle
{
    private:
        double* v[25];
    public:
        Triangle()
        {
            for(int i=0 ; i<25 ; i++)
            {
                v[i] = new double[i+1];
            }

            for(int i=0 ; i<25 ; i++)
            {
                for(int j=0 ; j<i+1 ; j++)
                {
                    v[i][j]=rand() % 8 + 2;
                }
            }
        }

        void display()
        {
            for(int i=0 ; i<25 ; i++)
            {
                for(int j=0 ; j<i+1 ; j++)
                {
                    cout<<v[i][j]<<" ";
                }
                cout<<endl;
            }
        }


        ~Triangle()
        {
            for(int i=0 ; i<25 ; i++)
            {
                delete[] v[i];
            }
        }
};

int main()
{
    Triangle t;
    t.display();




    return 0;
}
