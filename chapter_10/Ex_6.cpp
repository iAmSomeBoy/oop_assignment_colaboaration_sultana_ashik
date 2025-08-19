#include <iostream>

int compstr(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    
    if (*s1 < *s2) return -1;
    if (*s1 > *s2) return 1;
    return 0;
}

int main() {
    // Test cases
    const char* test1a = "apple";
    const char* test1b = "banana";
    std::cout << "Comparing '" << test1a << "' and '" << test1b << "': " 
              << compstr(test1a, test1b) << std::endl;

    const char* test2a = "zebra";
    const char* test2b = "apple";
    std::cout << "Comparing '" << test2a << "' and '" << test2b << "': " 
              << compstr(test2a, test2b) << std::endl;

    const char* test3a = "hello";
    const char* test3b = "hello";
    std::cout << "Comparing '" << test3a << "' and '" << test3b << "': " 
              << compstr(test3a, test3b) << std::endl;

    const char* test4a = "Hello";
    const char* test4b = "hello";
    std::cout << "Comparing '" << test4a << "' and '" << test4b << "': " 
              << compstr(test4a, test4b) << std::endl;

    const char* test5a = "apple";
    const char* test5b = "apples";
    std::cout << "Comparing '" << test5a << "' and '" << test5b << "': " 
              << compstr(test5a, test5b) << std::endl;

    const char* test6a = "";
    const char* test6b = "";
    std::cout << "Comparing '" << test6a << "' and '" << test6b << "': " 
              << compstr(test6a, test6b) << std::endl;

    return 0;
}