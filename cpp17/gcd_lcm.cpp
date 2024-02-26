#include <numeric>

int main()
{
    constexpr int A = 4;
    constexpr int B = 10;
    static_assert(std::gcd(A,B) == 2);
    static_assert(std::lcm(A,B) == 20);
}