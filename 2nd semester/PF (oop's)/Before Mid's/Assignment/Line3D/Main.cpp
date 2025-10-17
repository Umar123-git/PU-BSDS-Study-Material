#include "Line.h"
#include<iostream>
#include<cmath>
using namespace std;





int main()
{
    Point A(1,2), B(3,4), C(2,3), D(4,5);
    Line3D L1(A, B), L2(C, D);
    
    cout << "\nTesting Lines:" << endl;
    L1.disply();
    L2.disply();
    

    cout << "\nChecking if lines are parallel:" << endl;
    L1.Parallel(L1, L2);
    

    cout << "\nChecking if lines are concurrent:" << endl;
    L1.Concurrent(L1, L2);
    

    cout << "\nComputing Point of Intersection:" << endl;
    L1.point_of_intersection(L1, L2);

    cout << "\nChecking if lines are Horizontal or Vertical:" << endl;
    L1.Test_of_horizontal_and_vertical(L1);
    L2.Test_of_horizontal_and_vertical(L2);
    

    Point P(5, 6);
    cout << "\nDistance of Point ";
    P.disply();
    cout << " from Line1: " << L1.pointDistance(P) << endl;
    
    return 0;
}
