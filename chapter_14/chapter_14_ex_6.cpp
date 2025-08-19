#include <iostream>
using namespace std;
#include <process.h>    //for exit()

const int LIMIT = 10;    // Smaller array size for better output

class safearray
{
private:
    int arr[LIMIT];
public:
    int& operator [](int n)
    {
        if( n < 0 || n >= LIMIT )
        { 
            cout << "\nIndex " << n << " out of bounds!"; 
            exit(1); 
        }
        return arr[n];
    }
};

int main()
{
    safearray sa1;

    // Insert elements
    for(int j = 0; j < LIMIT; j++)
        sa1[j] = j * 10;

    // Display first 5 and last 5 elements
    cout << "First 5 elements:" << endl;
    for(int j = 0; j < 5; j++)
        cout << "Element " << j << " is " << sa1[j] << endl;

    cout << "\nLast 5 elements:" << endl;
    for(int j = LIMIT-5; j < LIMIT; j++)
        cout << "Element " << j << " is " << sa1[j] << endl;

    // Test bounds checking
    cout << "\nTesting bounds checking..." << endl;
    // sa1[-1] = 100;  // Uncomment to test lower bound error
    // sa1[10] = 200;  // Uncomment to test upper bound error

    cout << "Program completed successfully!" << endl;
    return 0;
}