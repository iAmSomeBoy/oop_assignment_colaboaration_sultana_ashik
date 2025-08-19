#include <iostream>
using namespace std;

class UnifiedArray {
private:
    static const int NUM_ARRAYS = 10;
    static const int ARRAY_SIZE = 5; // Size of each individual array
    int* arrays[NUM_ARRAYS]; // Array of pointers to individual arrays

public:
    // Constructor
    UnifiedArray() {
        // Allocate and initialize each array
        for (int i = 0; i < NUM_ARRAYS; i++) {
            arrays[i] = new int[ARRAY_SIZE];
            // Fill with test data (i*10 + j)
            for (int j = 0; j < ARRAY_SIZE; j++) {
                *(arrays[i] + j) = i * 10 + j;
            }
        }
    }

    // Destructor
    ~UnifiedArray() {
        for (int i = 0; i < NUM_ARRAYS; i++) {
            delete[] arrays[i];
        }
    }

    // Overloaded subscript operator
    int& operator[](int index) {
        if (index < 0 || index >= NUM_ARRAYS * ARRAY_SIZE) {
            cerr << "Index out of bounds!" << endl;
            // Return first element as fallback
            static int dummy;
            return dummy;
        }
        
        int arrayIndex = index / ARRAY_SIZE;
        int elementIndex = index % ARRAY_SIZE;
        return *(arrays[arrayIndex] + elementIndex);
    }

    // Display all elements
    void display() const {
        for (int i = 0; i < NUM_ARRAYS; i++) {
            cout << "Array " << i << ": ";
            for (int j = 0; j < ARRAY_SIZE; j++) {
                cout << *(arrays[i] + j) << " ";
            }
            cout << endl;
        }
    }

    // Get total size
    int size() const {
        return NUM_ARRAYS * ARRAY_SIZE;
    }
};

int main() {
    UnifiedArray a;

    // Display using class method
    cout << "Displaying arrays individually:" << endl;
    a.display();

    // Access as single array using overloaded []
    cout << "\nAccessing as single array:" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    // Modify some elements
    a[12] = 999;  // Should modify array 2, element 2
    a[49] = 1000; // Last element

    // Verify changes
    cout << "\nAfter modifications:" << endl;
    cout << "a[12] = " << a[12] << endl;
    cout << "a[49] = " << a[49] << endl;

    // Test bounds checking
    cout << "\nTesting bounds:" << endl;
    cout << "a[-1] = " << a[-1] << endl;    // Should show error
    cout << "a[50] = " << a[50] << endl;    // Should show error

    return 0;
}