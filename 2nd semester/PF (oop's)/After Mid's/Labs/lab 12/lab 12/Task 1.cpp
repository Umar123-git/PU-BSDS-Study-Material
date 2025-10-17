#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Painting {
protected:
    string title;
    string name;
    double value;

public:
    Painting() {
        title = " ";
        name = " ";
        value = 400.0;
    }

    Painting(string t, string n, double v) {
        title = t;
        name = n;
        value = v;
    }

    Painting(string t, string n) {
        title = t;
        name = n;
        value = 400.0; 
    }

    virtual void display() const {
        cout << "Painting Details:\n";
        cout << "Title: " << title << endl;
        cout << "Artist: " << name << endl;
        cout << "Value: $" << fixed << setprecision(2) << value << endl;
    }

    virtual ~Painting() {}
};

class FamousPainting : public Painting {
public:
    FamousPainting(string t, string n) : Painting(t, n) {
        value = 25000.0;
    }

    void display() const override {
        cout << "Famous Painting Details:\n";
        cout << "Title: " << title << endl;
        cout << "Artist: " << name << endl;
        cout << "Value: $" << fixed << setprecision(2) << value << endl;
    }
};

bool isFamous(const string arr[], const string &nam) {
    for (int i = 0; i < 4; i++) {
        if (nam == arr[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    Painting* p[7]; 
    string famousArtists[4] = {"Degas", "Monet", "Picasso", "Rembrandt"};
    string name, title;

    for (int i = 0; i < 7; i++) {
        cout << "Enter the name of the artist: ";
        getline(cin, name);

        cout << "Enter the title of the painting: ";
        getline(cin, title);

        if (isFamous(famousArtists, name)) {
            p[i] = new FamousPainting(title, name); 
        } else {
            p[i] = new Painting(title, name); 
        }
    }

    cout << "\nDisplaying Painting Details:\n";
    for (int i = 0; i < 7; i++) {
        p[i]->display();
        
    }


    for (int i = 0; i < 7; i++) {
        delete p[i];
    }

    return 0;
}