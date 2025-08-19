#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Name {
private:
    string firstName;
    char middleInitial;
    string lastName;
    unsigned long employeeNumber;

public:
    // Function to input data from user
    void input() {
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Middle Initial: ";
        cin >> middleInitial;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter Employee Number: ";
        cin >> employeeNumber;
    }

    // Function to display object data
    void display() const {
        cout << "Employee Number: " << employeeNumber << "\n"
             << "Name: " << firstName << " " << middleInitial << ". " << lastName << "\n"
             << "--------------------------------------" << endl;
    }

    // Write object to file (append mode)
    void writeToFile(const string& filename) const {
        ofstream fout(filename, ios::app);  // append mode
        if (!fout) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }
        fout << firstName << " " << middleInitial << " " << lastName << " " << employeeNumber << endl;
        fout.close();
    }

    // Read record by number (0-based index)
    bool readFromFile(const string& filename, int recordNumber) {
        ifstream fin(filename);
        if (!fin) {
            cerr << "Error opening file for reading!" << endl;
            return false;
        }

        int current = 0;
        while (fin >> firstName >> middleInitial >> lastName >> employeeNumber) {
            if (current == recordNumber) {
                fin.close();
                return true;
            }
            current++;
        }
        fin.close();
        return false; // record not found
    }
};

int main() {
    const string filename = "employees.txt";
    int choice;

    do {
        cout << "\n===== Employee Data Menu =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Display Specific Record\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Name emp;
            emp.input();
            emp.writeToFile(filename);
            cout << "Employee record saved!\n";
        }
        else if (choice == 2) {
            ifstream fin(filename);
            if (!fin) {
                cerr << "No employee data found.\n";
                continue;
            }

            cout << "\n===== All Employees =====\n";
            Name emp;
            while (fin >> emp.firstName >> emp.middleInitial >> emp.lastName >> emp.employeeNumber) {
                emp.display();
            }
            fin.close();
        }
        else if (choice == 3) {
            int recNo;
            cout << "Enter record number (0-based): ";
            cin >> recNo;
            Name emp;
            if (emp.readFromFile(filename, recNo)) {
                cout << "\n===== Employee Record =====\n";
                emp.display();
            } else {
                cout << "Record not found.\n";
            }
        }
        else if (choice == 4) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
