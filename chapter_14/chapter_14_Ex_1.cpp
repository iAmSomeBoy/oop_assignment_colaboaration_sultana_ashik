#include <iostream>

template <typename T>
double average(T arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return size ? sum / size : 0;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    long longArr[] = {10, 20, 30, 40, 50};
    double doubleArr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    
    std::cout << average(intArr, 5) << std::endl
              << average(longArr, 5) << std::endl
              << average(doubleArr, 5) << std::endl
              << average(charArr, 5) << std::endl;
}