#include <functional>
#include <iostream>
#include <tuple>

int main()
{
    auto Sum = [](int x, int y, int z) { return x + y + z; };
    auto resultFromInvoke = std::invoke(Sum, 1, 2, 5);

    std::tuple myTuple {1, 2, 5};
    auto resultFromApply  = std::apply(Sum, myTuple);

    std::cout << resultFromInvoke << '\n' << resultFromApply << '\n';

}