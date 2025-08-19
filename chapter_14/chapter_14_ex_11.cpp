#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class String {
    enum { SZ=80 };
    char str[SZ];
public:
    class Error : public runtime_error {
    public: Error(const char* m) : runtime_error(m) {} };
    
    String() { str[0] = '\0'; }
    String(char s[]) {
        if(strlen(s) >= SZ) throw Error("String too long!");
        strcpy(str, s);
    }
    
    void display() const { cout << str; }
    
    String operator+(String s) const {
        if(strlen(str) + strlen(s.str) >= SZ) 
            throw Error("Concatenation too long!");
        String temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }
};

int main() {
    try {
        String s1 = "\nMerry Christmas!  ", s2 = "Happy new year!", s3;
        s1.display(); s2.display(); s3.display();
        s3 = s1 + s2;
        s3.display();
        cout << endl;
    }
    catch(const String::Error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}6