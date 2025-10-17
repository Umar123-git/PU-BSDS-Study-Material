// CHATGPT: create a complete class in CPP for city name (lahore, sialkot, kasur, pindi, gujrat, multan, layyah), their latitude and logitude, population, area, etc as data members, and getters setters constructors, methods, etc as function members. Later, create a program to manupulate the city in binary files, including CLI based options to add new city data, remove city by name (as per some standard), update city data by name, list all cities, etc


// This is not a professional code/implementation

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

class City {
private:
    char name[50];
    double latitude;
    double longitude;
    int population;
    double area;

public:
    City() {
        strcpy(name, "Unknown");
        latitude = longitude = area = 0.0;
        population = 0;
    }

    City(const char* nm, double lat, double lon, int pop, double ar) {
        setName(nm);
        latitude = lat;
        longitude = lon;
        population = pop;
        area = ar;
    }

    void setName(const char* nm) {
        strncpy(name, nm, sizeof(name));
        name[sizeof(name) - 1] = '\0';
    }

    void setLatitude(double lat) { latitude = lat; }
    void setLongitude(double lon) { longitude = lon; }
    void setPopulation(int pop) { population = pop; }
    void setArea(double ar) { area = ar; }

    const char* getName() const { return name; }
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
    int getPopulation() const { return population; }
    double getArea() const { return area; }

    void input() {
        cout << "Enter city name: ";
        cin.ignore();
        cin.getline(name, sizeof(name));
        cout << "Enter latitude: ";
        cin >> latitude;
        cout << "Enter longitude: ";
        cin >> longitude;
        cout << "Enter population: ";
        cin >> population;
        cout << "Enter area: ";
        cin >> area;
    }

    void display() const {
        cout << left << setw(15) << name
             << setw(12) << latitude
             << setw(12) << longitude
             << setw(12) << population
             << setw(10) << area << endl;
    }
};

const char* FILENAME = "cities.dat";

// Add new city
void addCity() {
    City city;
    city.input();

    ofstream out(FILENAME, ios::binary | ios::app);
    if (out) {
        out.write(reinterpret_cast<char*>(&city), sizeof(City));
        out.close();
        cout << "City added successfully.\n";
    } else {
        cerr << "Error opening file for writing.\n";
    }
}

// List all cities
void listCities() {
    ifstream in(FILENAME, ios::binary);
    if (!in) {
        cerr << "Error opening file.\n";
        return;
    }

    City city;
    cout << left << setw(15) << "Name"
         << setw(12) << "Latitude"
         << setw(12) << "Longitude"
         << setw(12) << "Population"
         << setw(10) << "Area" << endl;
    cout << string(60, '-') << endl;

    while (in.read(reinterpret_cast<char*>(&city), sizeof(City))) {
        city.display();
    }

    in.close();
}

// Update city by name
void updateCity(const char* targetName) {
    fstream file(FILENAME, ios::binary | ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file.\n";
        return;
    }

    City city;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&city), sizeof(City))) {
        if (strcmp(city.getName(), targetName) == 0) {
            cout << "Current details:\n";
            city.display();
            cout << "Enter new details:\n";
            city.input();

            file.seekp(-static_cast<int>(sizeof(City)), ios::cur);
            file.write(reinterpret_cast<char*>(&city), sizeof(City));
            found = true;
            cout << "City updated successfully.\n";
            break;
        }
    }

    file.close();
    if (!found)
        cout << "City not found.\n";
}

// Delete city by name
void deleteCity(const char* targetName) {
    ifstream in(FILENAME, ios::binary);
    ofstream out("temp.dat", ios::binary);

    if (!in || !out) {
        cerr << "Error accessing files.\n";
        return;
    }

    City city;
    bool deleted = false;

    while (in.read(reinterpret_cast<char*>(&city), sizeof(City))) {
        if (strcmp(city.getName(), targetName) != 0) {
            out.write(reinterpret_cast<char*>(&city), sizeof(City));
        } else {
            deleted = true;
        }
    }

    in.close();
    out.close();

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    if (deleted)
        cout << "City deleted successfully.\n";
    else
        cout << "City not found.\n";
}

// Add dummy data
void addDummyData() {
    vector<City> dummyCities = {
        City("Lahore", 31.5497, 74.3436, 11000000, 1772.0),
        City("Sialkot", 32.4945, 74.5229, 920000, 301.0),
        City("Kasur", 31.1156, 74.4467, 757000, 399.0),
        City("Pindi", 33.5651, 73.0169, 2090000, 259.0),
        City("Gujrat", 32.5742, 74.0754, 390000, 320.0),
        City("Multan", 30.1575, 71.5249, 1870000, 3721.0),
        City("Layyah", 30.9641, 70.9449, 340000, 6291.0)
    };

    ofstream out(FILENAME, ios::binary | ios::app);
    if (!out) {
        cerr << "Error writing dummy data.\n";
        return;
    }

    for (const auto& city : dummyCities) {
        out.write(reinterpret_cast<const char*>(&city), sizeof(City));
    }

    out.close();
    cout << "Dummy data added successfully.\n";
}

// CLI Menu
void menu() {
    int choice;
    char cityName[50];

    do {
        cout << "\n==== City Database Menu ====\n";
        cout << "0. Exit\n";
        cout << "1. List all cities\n";
        cout << "2. Add new city\n";
        cout << "3. Update city by name\n";
        cout << "4. Delete city by name\n";
        cout << "5. Add dummy data\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting program.\n";
                break;
            case 1:
                listCities();
                break;
            case 2:
                addCity();
                break;
            case 3:
                cout << "Enter city name to update: ";
                cin.ignore();
                cin.getline(cityName, sizeof(cityName));
                updateCity(cityName);
                break;
            case 4:
                cout << "Enter city name to delete: ";
                cin.ignore();
                cin.getline(cityName, sizeof(cityName));
                deleteCity(cityName);
                break;
            case 5:
                addDummyData();
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
