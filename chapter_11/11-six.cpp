#include <iostream>
#include <cmath>
using namespace std;

class bMoney {
public:
    double amount;
    bMoney(double a = 0) { amount = a; }
    void display() { cout << "" << amount << endl; }
};

bMoney round(const bMoney& m) {
    double intPart;
    double frac = modf(m.amount, &intPart);
    if (frac < 0.5) return bMoney(intPart);
    else return bMoney(intPart + 1);
}

int main() {
    bMoney arr[] = {12.20, 45.49, 33.50, 19.75, 100.10, 7.99};
    cout << "Original:\n";
 for (int i = 0; i < 6; i++) {
    arr[i].display();
}

cout << "Rounded:\n";
for (int i = 0; i < 6; i++) {
    bMoney r = round(arr[i]);
    r.display();
}

    return 0;
}


