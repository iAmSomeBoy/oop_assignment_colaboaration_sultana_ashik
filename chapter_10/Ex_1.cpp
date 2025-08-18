#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    // Dynamically allocate array
    float* numbers = new float[size];

    // Read numbers from user
    cout << "Enter " << size << " numbers, one per line:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> *(numbers + i); // Using pointer notation
    }

    // Calculate average
    float sum = 0.0f;
    for (int i = 0; i < size; i++) {
        sum += *(numbers + i); // Using pointer notation
    }
    float average = sum / size;

    // Print result
    cout << "The average is: " << average << endl;

    // Free allocated memory
    delete[] numbers;

    return 0;
}