#include <cassert>
#include <functional>

bool isEven(uint x)
{
    return x % 2 == 0;
}

int main()
{
    auto isOdd = std::not_fn(isEven);
    assert(isOdd(1) == true);
    assert(isOdd(2) == false);
}