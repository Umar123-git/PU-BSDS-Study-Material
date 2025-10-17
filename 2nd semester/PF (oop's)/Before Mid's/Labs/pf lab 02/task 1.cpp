#include<iostream>
#include<cmath>
using namespace std;

class Matrix33 {
protected:
    double m[3][3]; 

public:
   
    void setM(int row, int col, double val) {
        m[row][col] = val;
    }


    double getM(int row, int col) {
        return m[row][col];
    }

    Matrix33() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = 0; // Initialize with zero
            }
        }
    }


    Matrix33(double n[3][3])
    {
    	m[3][3]=n[3][3];
	}
    
    ~Matrix33()
    {
    	cout<<endl<<"I am dying ...\n"<<endl;
	}
	
	
    void setM1(int arr[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = arr[i][j];
            }
        }
    }

 
    void display() {
        cout<<endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << m[i][j] << "  ";
            }
            cout << endl;
        }
        cout << endl;
    }
    

	
	Matrix33 multiply(int num)
	{
		Matrix33 mult;
		    for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j]=m[i][j] * num; 
                mult.m[i][j]=m[i][j];
            }
        }
        display();
        return mult;
    }
		
	bool check(int arr[3][3]) 
	{
		 bool check = true;
        for (int i = 0; i < 3; i++) 
		{
            for (int j = 0; j < 3; j++)
			 {
			 	if(m[i][j] != arr[i][j])
			 	{
			 		check=false;
			 		return check;
				}
			 	
                
            }
        }
        return check;
    }
	
	
	void determinent()
	{
		double d;
		d=m[0][0]*((m[1][1]*m[2][2])-(m[1][2]*m[2][1]))   -   m[0][1]*((m[1][0]*m[2][2])-(m[1][2]*m[2][0]))  +  m[0][2]*((m[1][0]*m[2][1]-m[1][1]*m[2][0]));
		cout<<"\nDeterminent is equal to :"<<d;
	}

	};

int main() {
    Matrix33 mat;
    int val, arr[3][3];

  
   
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cin >> val;
            mat.setM(row, col, val);
        }
    }

    mat.display();

   
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cin >> arr[row][col];
        }
    }

    mat.setM1(arr);
    mat.display();
    
    int num;
    cout<<"\nwrite a number for scalar multiplication :";
    cin>>num;
    mat.multiply(num);

  	cout<<mat.check(arr);
  	
  	
  	mat.determinent();

    return 0;
}
