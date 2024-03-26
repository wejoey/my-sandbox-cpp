#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// Example from https://medium.com/@simontoth/daily-bit-e-of-c-std-transform-reduce-ae7a3772e848

int main() {
    std::vector<int> data{1,2,3};
    auto res = std::transform_reduce(data.begin(), data.end(),
        0,                           // init value
        std::plus<>{},               // reduce
        [](int v) { return v*v; });  // transform

    // transform   -> v[1*1, 2*2]
    // reduce plus -> (1*1) + (2*2) + (3*3)= 14
    // result: 5

    std::cout << res;


}
