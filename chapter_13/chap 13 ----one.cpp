#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class VeryLong {
private:
    string number;   
    bool negative;  

public:
    VeryLong(string s = "0") {
        if (s[0] == '-') {
            negative = true;
            number = s.substr(1);
        } else {
            negative = false;
            number = s;
        }
        
        number.erase(0, min(number.find_first_not_of('0'), number.size()-1));
    }

    void show() const {
        if (negative && number != "0") cout << "-";
        cout << number;
    }

    
    int absCompare(const VeryLong& other) const {
        if (number.length() != other.number.length())
            return number.length() - other.number.length();
        return number.compare(other.number);
    }

    
    VeryLong subtractAbs(const VeryLong& other) const {
        string result = "";
        int carry = 0;
        int n1 = number.length();
        int n2 = other.number.length();
        int diff = n1 - n2;

        for (int i = n2-1; i >= 0; i--) {
            int sub = (number[i+diff]-'0') - (other.number[i]-'0') - carry;
            if (sub < 0) { sub += 10; carry = 1; } else carry = 0;
            result.push_back(sub + '0');
        }

        
        for (int i = diff-1; i >= 0; i--) {
            int sub = (number[i]-'0') - carry;
            if (sub < 0) { sub += 10; carry = 1; } else carry = 0;
            result.push_back(sub + '0');
        }

        reverse(result.begin(), result.end());
        
        result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
        return VeryLong(result);
    }

   
    VeryLong operator-(const VeryLong& other) const {
        VeryLong a = *this;
        VeryLong b = other;

        
        if (a.negative != b.negative) {
            
            cout << "Addition for different signs not implemented in this simple version.\n";
            return VeryLong("0");
        }

       
        if (a.absCompare(b) >= 0) {
            VeryLong result = a.subtractAbs(b);
            result.negative = a.negative;
            return result;
        } else {
            VeryLong result = b.subtractAbs(a);
            result.negative = !a.negative;
            return result;
        }
    }

    
    VeryLong operator/(const VeryLong& other) const {
        if (other.number == "0") {
            cout << "Division by zero!\n";
            return VeryLong("0");
        }

        VeryLong dividend = *this;
        VeryLong divisor = other;
        dividend.negative = false;
        divisor.negative = false;

        string result = "";
        string temp = "";

        for (char c : dividend.number) {
            temp += c;
            
            temp.erase(0, min(temp.find_first_not_of('0'), temp.size()-1));

            int count = 0;
            VeryLong tempVL(temp);
            while (tempVL.absCompare(divisor) >= 0) {
                tempVL = tempVL - divisor;
                temp = tempVL.number;
                count++;
            }
            result.push_back(count + '0');
        }

        
        result.erase(0, min(result.find_first_not_of('0'), result.size()-1));
        VeryLong quotient(result);
        quotient.negative = (negative != other.negative && result != "0");
        return quotient;
    }
};

int main() {
    VeryLong a("12345");
    VeryLong b("123");

    VeryLong c = a - b;
    cout << "Subtraction: ";
    c.show();
    cout << endl;

    VeryLong d = a / b;
    cout << "Division: ";
    d.show();
    cout << endl;

    return 0;
}
