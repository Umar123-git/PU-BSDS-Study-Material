#include <iostream>
#include <string>
#include <exception>
#include <cmath>

using namespace std;

class Point3d
{
protected:
    float x, y, z;
public:
	float getx()const
	{
		return x;
	}
	float gety()const
	{
		return y;
	}
	float getz()const
	{
		return z;
	}
	// Default constructor
    Point3d() : x(0), y(0), z(0) {}
    
    // Parameterized constructor
	Point3d(float x, float y, float z) : x(x), y(y), z(z) {}
	
    // Displace the point by specified amounts
	void displace(float dx, float dy, float dz) 
	{
	    x += dx;
	    y += dy;
	    z += dz;
	}
	
    // Calculate distance to another point
	float distance(const Point3d &other) const 
	{
   	 	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
	}
	
    // Check if two points are equal
	bool operator==(const Point3d &other) const 
	{
    	return x == other.x && y == other.y && z == other.z;
	}
	
    // Check if two points are not equal
	bool operator!=(const Point3d &other) const 
	{
    	return !(*this == other);
	}
	
    // Scale point by a factor
	Point3d operator*(float scale) const 
	{
    	return Point3d(x * scale, y * scale, z * scale);
	}
	
    // Friend function to scale point using a scalar
	friend Point3d operator*(float scale, const Point3d &point) 
	{
    	return Point3d(point.x * scale, point.y * scale, point.z * scale);
	}
	
    // Divide point coordinates by a factor
	Point3d operator/(float scale) const 
	{
    	if (scale == 0) 
		{
        	throw invalid_argument("Error: Division by zero is not allowed.");
    	}
    	return Point3d(x / scale, y / scale, z / scale);
	}
    // Overload for output operator
	friend ostream &operator<<(ostream &strm, const Point3d &point) 
	{
    	return strm << "(" << point.x << ", " << point.y << ", " << point.z << ")";
	}
    // Overload for input operator
	friend istream &operator>>(istream &strm, Point3d &point) 
	{
	    cout << "Enter x, y, z: ";
	    strm >> point.x >> point.y >> point.z;
	    if (!strm) 
		{
	        throw invalid_argument("Error: Invalid input for Point3d.");
	    }
	    return strm;
	}
};
 
class Plane2D
{
	protected:
		float a , b , c;
	public:
		Plane2D()
		{
			a=0;
			b=0;
			c=0;
			cout<<"Default constructor \n";
		}
		
		Plane2D(float _a , float _b , float _c)
		{
			a=_a;
			b=_b;
			c=_c;
			cout<<"Parameterized constructor \n";
		}
		
		bool Pointliesontheplane(const Point3d& point)
		{
			cout<<"\nPoint lies on the plane : ";
			return(a*point.getx() + b*point.gety() + c == 0);
		}
		
		bool twoplanesequal(const Plane2D& p)
		{
			cout<<"\nAre the two planes equals : ";
			return (a/p.a==b/p.b) && (b/p.b==c/p.c);

		}
		
		bool twoplanesparallel(const Plane2D& p)
		{
			cout<<"\nAre the two planes parallel : ";
			return (a/p.a==b/p.b) && (b/p.b==c/p.c);

		}
		
		double distance(const Point3d& point)
		{
			cout<<"\nDistance : ";
			double absolute= abs(a*point.getx() + b*point.gety() + c);
			double sqroot  = sqrt((a*a) + (b*b));
			double dist    = absolute/sqroot;
			return dist;
		}
};

int main() {
    try {
        // Create points
        Point3d p1, p2(3, 4, 5);

        // Test constructors
        cout << "Default point: " << p1 << endl;
        cout << "Parameterized point: " << p2 << endl;

        // Test displacement
        p1.displace(1, 2, 3);
        cout << "After displacement: " << p1 << endl;

        // Test distance calculation
        cout << "Distance between points: " << p1.distance(p2) << endl;

        // Test equality and inequality
        cout << "Are points equal? " << (p1 == p2 ? "Yes" : "No") << endl;
        cout << "Are points not equal? " << (p1 != p2 ? "Yes" : "No") << endl;

        // Test scaling
        Point3d p3 = p2 * 2;
        cout << "Point scaled up: " << p3 << endl;

        Point3d p4 = p2 / 2;
        cout << "Point scaled down: " << p4 << endl;

        // Test input
        Point3d p5;
        cin >> p5;
        cout << "You entered: " << p5 << endl;
        
        
        
        Plane2D p(2,3,-1);
        Plane2D q(2,3,-1);
        cout<<p.Pointliesontheplane(p5);
        cout<<p.twoplanesequal(q);
        cout<<p.distance(p5);

    } catch (const exception &e) {
        cerr << e.what() << endl; // Output exception message
    }

    return 0;
}

