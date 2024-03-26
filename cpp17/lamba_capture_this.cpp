#include <iostream>

// Examples from
// https://github.com/AnthonyCalandra/modern-cpp-features/tree/master
// https://en.cppreference.com/w/cpp/language/lambda

struct MyClass {
    char x{'Y'};
    auto getMyChar(){
        return [&] { return x; };        // Implicit capture this by ref
        // return [=] { return x; };        // Implicit capture this by ref
        // return [this] { return x; };     // Explicit capture this by ref
        // return [&, this] { return x; };  // Explicit capture this by ref
        // return [*this] { return x; };    // [C++17] Capture this by copy
        // return [=, *this] { return x; }; // [C++17] Explicit capture this by copy
        // return [=, this] { return x; };  // [C++20] Explicit capture this by ref
    }
};

int main()
{
    MyClass myClass;
    auto lamda = myClass.getMyChar();

    std::cout << lamda() << "\n";
    myClass.x = 'Z';
    std::cout << lamda() << "\n";
}
