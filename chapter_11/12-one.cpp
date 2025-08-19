#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    virtual void getdata() {
        cin.ignore(); 
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }

};

class Book : public Publication {
private:
    int pages;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pages;
    }

    void putdata() override {
        Publication::putdata();
        cout << "Pages: " << pages << endl;
    }
};

class Tape : public Publication {
private:
    float playTime;

public:
    void getdata() override {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playTime;
    }

    void putdata() override {
        Publication::putdata();
        cout << "Playing time: " << playTime << " minutes" << endl;
    }
};

int main() {
    int n;
    cout << "How many publications do you want to enter? ";
    cin >> n;

    Publication* pubarr[n];

    for (int i = 0; i < n; i++) {
        int choice;
        cout << "\nEnter 1 for Book, 2 for Tape: ";
        cin >> choice;

        if (choice == 1)
            pubarr[i] = new Book();
        else
            pubarr[i] = new Tape();

        pubarr[i]->getdata();
    }

    cout << "\n--- Publications Entered ---\n";
    for (int i = 0; i < n; i++) {
        cout << "\nPublication " << (i + 1) << " details:\n";
        pubarr[i]->putdata();
    }

    return 0;
}
