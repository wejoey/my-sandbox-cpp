#include <cassert>
#include <numeric>

int main()
{
    constexpr int A = 4;
    constexpr int B = 10;
    assert(std::gcd(A,B) == 2);
    assert(std::lcm(A,B) == 20);
}