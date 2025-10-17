#include <iostream>
using namespace std;

struct pairs{
    int x;
    int y;
};

class Squares
{
    private:
        pairs Xrange;
        pairs Yrange;
        pairs center;
        int count;

    public:
       /* Squares(){
            count = 0;
            center.x = 1024;
            center.y = 1024;
        }
        Squares(pairs center, int k)
        {            
            Xrange.x = 1024-k;
            Xrange.y = 1024+k;
            Yrange.x = 1024-k;
            Yrange.y = 1024+k;
        }
*/

        int scount(int k, int px, int py, pairs center)
        {
            if(k<1)return 0;

           // Squares(center,k);
           // Squares(center,k);
            
            pairs Xrange = {center.x-k, center.x +k};
            pairs Yrange = {center.y-k, center.y +k};

            if(px>=Xrange.x && px<=Xrange.y && py>=Yrange.x && py<=Yrange.y)
            {
                count++;
            }
            
            pairs topLeft = {center.x - k, center.y - k};
            pairs topRight= {center.x - k, center.y + k};
            pairs bottomLeft= {center.x + k, center.y - k};
            pairs bottomRight= {center.x + k, center.y + k};

            scount(k/2, px, py, topLeft);
            scount(k/2, px, py, topRight);
            scount(k/2, px, py, bottomLeft);
            scount(k/2, px, py, bottomRight);


            //scount(k/2 ,a, b);
            return count;

        }
};

int main()
{
    //Squares s(500,113,941);
    //cout<<s.scount(500,113,941);

    Squares s;
    int k=500, x = 113 , y=941;
    pairs center = {1024,1024};
    cout<<s.scount(k,x,y,center);
    
    return 0;
}