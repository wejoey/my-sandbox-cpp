#include <iostream>

#define BEFORE_CPP17 1

#if BEFORE_CPP17

// header
struct MyClass {
    static char myChar;
};

//cpp
char MyClass::myChar = 'X';

#else

// header
struct MyClass {
    inline static char myChar{'Y'};
};

#endif

int main()
{
    std::cout << MyClass::myChar << "\n";
}
