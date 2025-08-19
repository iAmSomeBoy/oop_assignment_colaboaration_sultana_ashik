#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Name {
private:
    string firstName;
    char middleInitial;
    string lastName;
    int empNumber;

public:
    
    void get() {
        cout << "First name: "; cin >> firstName;
        cout << "Middle initial: "; cin >> middleInitial;
        cout << "Last name: "; cin >> lastName;
        cout << "Employee number: "; cin >> empNumber;
    }

    
    void show() {
        cout << firstName << " " << middleInitial << ". " << lastName 
             << ", Emp#: " << empNumber << endl;
    }

    
    void writeToFile() {
        ofstream out("employees.txt", ios::app); 
        out << firstName << " " << middleInitial << " " << lastName 
            << " " << empNumber << endl;
        out.close();
    }

   
    void readFromFile(int recordNum) {
        ifstream in("employees.txt");
        int count = 0;
        while (in >> firstName >> middleInitial >> lastName >> empNumber) {
            count++;
            if (count == recordNum) break;
        }
        in.close();

        if (count == recordNum)
            show();
        else
            cout << "Record not found!" << endl;
    }
};

int main() {
    Name emp;
    char choice;
    
    do {
        emp.get();
        emp.writeToFile();
        cout << "Add another employee? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    int rec;
    cout << "\nEnter record number to read: ";
    cin >> rec;
    emp.readFromFile(rec);

    return 0;
}
