#include<iostream>
using namespace std;


double knapsack01(int n, int W, double w[], double v[]){
    if(n<=0 || W<=0) return 0;
    if(n>0 && w[n]>W) return knapsack01(n-1, W, w, v);
    return max(knapsack01(n-1, W, w, v), knapsack01(n-1, W-w[n], w, v)+v[n]);
}
int main()
{
    int n = 3;                 // number of items
    int W = 50;                // knapsack capacity

    double w[] = {10, 20, 30}; // weights of items
    double v[] = {60, 100, 120}; // values of items

    // Call the recursive function
    double maxBenefit = knapsack01(n, W, w, v);

    // Print the result
    cout << "Maximum benefit = " << maxBenefit << endl;
    return 0;
}