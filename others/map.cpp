#include <iostream>
#include <map>
#include <memory>
#include <unordered_map>

class MyClass
{
public:

private:
int m_x{-1};
int m_y{-1};
};

int main()
{
    using MyMap = std::map<uint, std::unordered_map<uint, std::unique_ptr<MyClass>>>;

    //MyClass myClassA = MyClass();

    MyMap myMap;

    myMap.insert(std::make_pair(1, std::unordered_map<uint, std::unique_ptr<MyClass>>()));

}