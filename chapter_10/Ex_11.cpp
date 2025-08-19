#include <iostream>
using namespace std;

class UnifiedArray {
private:
    static const int NUM_ARRAYS = 10;
    static const int ARRAY_SIZE = 5;
    int* arrays[NUM_ARRAYS];

public:
    UnifiedArray() {
        for (int i = 0; i < NUM_ARRAYS; i++) {
            arrays[i] = new int[ARRAY_SIZE];
            for (int j = 0; j < ARRAY_SIZE; j++) {
                *(arrays[i] + j) = i * 10 + j;
            }
        }
    }

    ~UnifiedArray() {
        for (int i = 0; i < NUM_ARRAYS; i++) {
            delete[] arrays[i];
        }
    }

    int& operator[](int index) {
        if (index < 0 || index >= NUM_ARRAYS * ARRAY_SIZE) {
            cerr << "Index out of bounds!" << endl;
            static int dummy;
            return dummy;
        }
        return *(arrays[index / ARRAY_SIZE] + index % ARRAY_SIZE);
    }

    void displaySummary() const {
        cout << "First 3 arrays and last array:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Array " << i << ": ";
            for (int j = 0; j < ARRAY_SIZE; j++) {
                cout << *(arrays[i] + j) << " ";
            }
            cout << endl;
        }
        cout << "...\nArray 9: ";
        for (int j = 0; j < ARRAY_SIZE; j++) {
            cout << *(arrays[9] + j) << " ";
        }
        cout << endl;
    }

    int size() const { return NUM_ARRAYS * ARRAY_SIZE; }
};

int main() {
    UnifiedArray a;

    cout << "=== Array Summary ===\n";
    a.displaySummary();

    cout << "\n=== Sample Accesses ===\n";
    cout << "a[0] = " << a[0] << endl;
    cout << "a[12] = " << a[12] << " (before modification)\n";
    cout << "a[49] = " << a[49] << " (before modification)\n";

    a[12] = 999;
    a[49] = 1000;

    cout << "\n=== After Modifications ===\n";
    cout << "a[12] = " << a[12] << endl;
    cout << "a[49] = " << a[49] << endl;

    cout << "\n=== Bounds Testing ===\n";
    cout << "a[-1]: ";
    cout << a[-1] << endl;
    cout << "a[50]: ";
    cout << a[50] << endl;

    return 0;
}