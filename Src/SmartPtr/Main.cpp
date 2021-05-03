#include <iostream>

class MyClass
{
public:
    MyClass() { std::cout << "MyClass created" << std::endl; };
    ~MyClass() { std::cout << "MyClass destroyed" << std::endl; };
};

int main()
{
    MyClass* ptr1;
    MyClass* ptr2;

    {
        std::unique_ptr<MyClass> myClassPtr1 = std::make_unique<MyClass>();
        std::shared_ptr<MyClass> myClassPtr2 = std::make_shared<MyClass>();

        ptr1 = myClassPtr1.get();
        ptr2 = myClassPtr2.get();
    }



}