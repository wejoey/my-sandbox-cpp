#include <functional>
#include <iostream>
#include <type_traits>

int Sum(int x, int y){ return x + y; }

int main()
{
    static_assert(std::is_invocable_r_v<int, decltype(Sum), int, int>);

    static_assert(std::is_integral_v<std::invoke_result<decltype(Sum), int, int>::type>);
    static_assert(std::is_signed_v<std::invoke_result<decltype(Sum), int, int>::type>);
}