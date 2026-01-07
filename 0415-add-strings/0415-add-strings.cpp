#include <string>

class Solution {
public:
    string addStrings(string num1, string num2) {
        return num1.length() > num2.length() ? getResult(num1, num2) : getResult(num2, num1);
    }

    string getResult(string longer, string shorter) {
        string result = "";
        unsigned int carry = 0;
        std::string::iterator iter1 = (--longer.end());
        for (std::string::iterator iter2 = (--shorter.end()); iter2 != (--shorter.begin()); --iter2) {
            unsigned int value = (unsigned int)(*(iter1--) - '0') + (unsigned int)(*iter2 - '0') + carry;
            result = (char)((value % 10) + '0') + result;
            carry = (value) / 10;
        }
        for (; iter1 != (--longer.begin()); --iter1) {
            unsigned int value = (unsigned int)(*iter1 - '0') + carry;
            result = (char)((value % 10) + '0') + result;
            carry = (value) / 10;
        }
        while (carry > 0) {
            result = (char)(carry + '0') + result;
            carry /= 10;
        }
        return result;
    }
};