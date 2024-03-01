#include <iomanip>
#include <iostream>

int main()
{
    std::cout << std::quoted("test1") << "\n";
    std::cout << std::quoted("test2", '`') << "\n";
}