#include <iostream>
using namespace std;

class bMoney {
private:
    double amount;  

public:
    bMoney(double a = 0.0) { amount = a; }

    friend ostream& operator<<(ostream& out, const bMoney& m);
    friend istream& operator>>(istream& in, bMoney& m);
};


ostream& operator<<(ostream& out, const bMoney& m) {
    out << "$ : " << m.amount;
    return out;
}

istream& operator>>(istream& in, bMoney& m) {
    cout << "Enter amount: ";
    in >> m.amount;
    return in;
}

int main() {
    bMoney money1, money2;

    cin >> money1;
    cin >> money2;

    
    cout << "You entered: " << money1 << " and " << money2 << endl;

    return 0;
}
