#include <iostream>
using namespace std;
int main()
 {

    int distances[] = {100, 150, 200, 250, 300};
    int times[] = {2, 3, 4, 5, 6};
    int size = sizeof(distances) / sizeof(distances[0]);

    cout << "Distance /Time /Speed (km/hr)" << endl;
    int i=0;
    while ( i < size)
	 {
        double speed = (distances[i]) / (times[i]);
        cout << distances[i] << "\t\t" << times[i] << "\t\t" << speed << endl;
        i++;
    }

    return 0;
}
