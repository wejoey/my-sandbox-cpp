#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> v{1, 5, 10};
  {
    std::vector<int> results{};
    results.reserve(v.size());
    std::inclusive_scan(v.begin(), v.end(), std::back_inserter(results),
                        std::plus<>(), 0);
    // [s0, s1, s2]
    // s0 = init + v[0]               = 1
    // s1 = init + v[0] + v[1]        = 6
    // s2 = init + v[0] + v[1] + v[2] = 16

    for (const auto i : results) {
      std::cout << i << " ";
    }
  }
  {
    std::vector<int> results{};
    std::exclusive_scan(v.begin(), v.end(), std::back_inserter(results), 0,
                        std::plus<>());
    // [s0, s1, s2]
    // s0 = init                = 0
    // s1 = init + v[0]         = 1
    // s2 = init + v[0] + v[1]  = 6

    for (const auto i : results) {
      std::cout << i << " ";
    }
  }
}
