#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Name {
private:
    string firstName;
    char middleInitial;
    string lastName;
    unsigned long employeeNumber;

public:
    // Constructor
    Name() : middleInitial(' '), employeeNumber(0) {}
    Name(string fname, char mi, string lname, unsigned long empNum)
        : firstName(fname), middleInitial(mi), lastName(lname), employeeNumber(empNum) {}

    // Member function to write data to file
    void writeToFile(ofstream& outFile) const {
        outFile << firstName << ' ' << middleInitial << ' ' << lastName << ' ' << employeeNumber << '\n';
    }

    // Member function to read data from file
    bool readFromFile(ifstream& inFile) {
        if (inFile >> firstName >> middleInitial >> lastName >> employeeNumber) {
            return true;
        }
        return false;
    }

    // Display function
    void display() const {
        cout << "Employee: " << lastName << ", " << firstName << " " << middleInitial << ". (" << employeeNumber << ")\n";
    }

    // Getter for employee number (useful for searching)
    unsigned long getEmployeeNumber() const {
        return employeeNumber;
    }
};

void writeEmployeeData() {
    ofstream outFile("employees.dat", ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing!\n";
        return;
    }

    char choice;
    do {
        string fname, lname;
        char mi;
        unsigned long empNum;

        cout << "\nEnter employee details:\n";
        cout << "First name: ";
        cin >> fname;
        cout << "Middle initial: ";
        cin >> mi;
        cout << "Last name: ";
        cin >> lname;
        cout << "Employee number: ";
        cin >> empNum;

        Name emp(fname, mi, lname, empNum);
        emp.writeToFile(outFile);

        cout << "Add another employee? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    outFile.close();
    cout << "Data saved to file.\n";
}

void readAndDisplayAllData() {
    ifstream inFile("employees.dat");
    if (!inFile) {
        cerr << "Error opening file for reading!\n";
        return;
    }

    cout << "\n=== Employee Records ===\n";
    Name emp;
    int recordCount = 0;

    while (emp.readFromFile(inFile)) {
        cout << "Record #" << ++recordCount << ": ";
        emp.display();
    }

    if (recordCount == 0) {
        cout << "No records found in file.\n";
    }

    inFile.close();
}

int main() {
    cout << "Employee Data Management System\n";
    cout << "==============================\n";

    // Write data to file
    writeEmployeeData();

    // Read and display all data
    readAndDisplayAllData();

    return 0;
}