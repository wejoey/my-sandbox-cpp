#include <algorithm>
#include <iostream>

int main()
{
    int x = 0;

    // if x<=1
    //   return 1
    // if x>=5
    //   return 5
    // else
    //   return x
    auto result = std::clamp(x,1,5);

    std::cout << result;
}