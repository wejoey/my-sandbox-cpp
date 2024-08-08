#include <iostream>
#include <utility>

class MyClass
{
public:
#if 1
#define EXPLICIT explicit
#else
#define EXPLICIT
#endif
    EXPLICIT MyClass(std::string str) : m_str(std::move(str)) {
        std::cout << "Created std::string" << std::endl;
    }
    EXPLICIT MyClass(int x, int y) : m_x(x), m_y(y) {
        std::cout << "Created int x,y" << std::endl;
    }

    void Print(){
        std::cout << m_str << m_x << m_y << std::endl;
    }

private:

std::string m_str{"---"};
int m_x{-1};
int m_y{-1};
};

void doSomething(MyClass m){
    m.Print();
}

int main()
{
    MyClass myClassA = MyClass("str");
    MyClass myClassB = MyClass(1,2);

    doSomething(myClassA);
    doSomething(myClassB);

    std::string test_str("test");
    doSomething({test_str});
    doSomething(test_str);

    doSomething({1,2});

}