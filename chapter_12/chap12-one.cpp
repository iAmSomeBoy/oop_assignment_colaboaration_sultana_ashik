#include <iostream>
#include <fstream>
using namespace std;

class Distance {
public:
    int feet;
    float inches;

    void get() {
        cout << "Feet: "; cin >> feet;
        cout << "Inches: "; cin >> inches;
    }

    void show() {
        cout << feet << " ft " << inches << " in" << endl;
    }
};

int main() {
    Distance d;
    ofstream out("distance.dat", ios::app | ios::binary); 
    char more = 'y';
    while(more == 'y' || more == 'Y') {
        d.get();
        out.write((char*)&d, sizeof(d));
        cout << "Add more? (y/n): ";
        cin >> more;
    }
    out.close();


    ifstream in("distance.dat", ios::binary);
    cout << "\nAll distances in file:\n";
    while(in.read((char*)&d, sizeof(d))) {
        d.show();
    }
    in.close();

    return 0;
}
