#include <iostream>
using namespace std;
#include <process.h>    //for exit()

const int LIMIT = 100;    //array size

class safearray
{
private:
    int arr[LIMIT];
public:
    int& operator [](int n) //note: return by reference
    {
        if( n < 0 || n >= LIMIT )
        { 
            cout << "\nIndex out of bounds"; 
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
        sa1[j] = j * 10;    //"left" side of equal sign

    // Display elements
    for(int j = 0; j < LIMIT; j++)
    {
        int temp = sa1[j];    //"right" side of equal sign
        cout << "Element " << j << " is " << temp << endl;
    }

    // Test bounds checking (uncomment to test)
    // sa1[-1] = 100;  // Should cause error
    // sa1[100] = 200; // Should cause error

    return 0;
}