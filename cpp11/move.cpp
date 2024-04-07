#include <cstring>
#include <iostream>

// inspired from theCherno
class MyClass
{
public:
    MyClass() = default;
    MyClass(const char* str)
    {
        std::cout << "Created" << std::endl;
        mSize = strlen(str);
        mData = new char[mSize];
        memcpy(mData, str, mSize);
    }

    //copy constructor
    MyClass(const MyClass& other)
    {
        std::cout << "Copied" << std::endl;
        mSize = other.mSize;
        mData = new char[mSize];
        memcpy(mData, other.mData, mSize);
    }

    //move constructor
    //rvalue reference since c++11
    MyClass(MyClass&& other) noexcept
    {
        std::cout << "Moved" << std::endl;
        mSize = other.mSize;
        mData = other.mData;

        other.mSize = 0;
        other.mData = nullptr; // to avoid to lose the ptr in the destructor
    }

    //assign operator
    MyClass& operator=(MyClass&& other) noexcept
    {
        std::cout << "Assigned" << std::endl;

        if (this != &other)
        {
            delete[] mData; // delete before to avoid memory leak

            mSize = other.mSize;
            mData = other.mData;

            other.mSize = 0;
            other.mData = nullptr; // to avoid to lose the ptr in the destructor
        }
        return *this;
    }

    ~MyClass()
    {
        std::cout << "Destructed" << std::endl;
        delete mData;
    }

    void Print()
    {
        for (int i = 0; i < mSize; i++)
        {
            std::cout << static_cast<char>(mData[i]);
        }
        std::cout << std::endl;
    }

private:
    char* mData;
    int mSize;
};

class EntityA
{
public:
    EntityA(const MyClass& name)
        : mName(name)
    {
    }

    EntityA(MyClass&& name)
        : mName(std::move(name))
    {
    }

    void PrintName()
    {
        mName.Print();
    }

private:
    MyClass mName;
};

class EntityB
{
public:
    EntityB(MyClass& name)
        : mName(name)
    {
    }

    void PrintName()
    {
        mName.Print();
    }

private:
    MyClass& mName;
};
int main()
{
    EntityA entityA("myEntityA");
    entityA.PrintName();

    MyClass myClassB = MyClass("myEntityB");
    EntityB entityB(myClassB);
    entityB.PrintName();

    //move
    MyClass i1 = "i1";
    //MyClass i2 = i1;
    //MyClass i2(MyClass("i1"));
    MyClass i2(std::move(i1));   // require a move constructor
    MyClass i3;
    i3 = std::move(i2);  // requires an assign overload
}