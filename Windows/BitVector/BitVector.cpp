// BitVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class UniqueCharBitVector {

public:
    bool isUnique(std::string input) {

        if (input.length() > 26) {
            return false;
        }

        int checker = 0;

        for (char& c : input) {
            int charBitVector = 1 << (c - 'a');
            if ((checker & charBitVector) > 0) {
                return false;
            }
            checker = checker | charBitVector;
        }
        return true;
    }
};


int main()
{
    UniqueCharBitVector instance;

    std::string s1 = "abcdef";
    std::string s2 = "abcabc";

    std::cout << "Testing s1 " + s1 + " = " << (instance.isUnique(s1) ? "True" : "False") << std::endl;
    std::cout << "Testing s2 " + s2 + " = " << (instance.isUnique(s2) ? "True" : "False") << std::endl;
}
