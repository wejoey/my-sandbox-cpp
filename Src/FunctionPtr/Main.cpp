#include <iostream>

void testFct(int input)
{
    std::cout << "Test Function Pointer: " << input << std::endl;
}

int main()
{
    void(*testFctPtr1)(int) = testFct;
    auto testFctPtr2 = testFct;
    auto testFctPtr3 = [](int a) { std::cout << "hello from Lamda: " << a << std::endl; };

    testFct(0);
    testFctPtr1(1);
    testFctPtr2(2);
    testFctPtr3(3);
}