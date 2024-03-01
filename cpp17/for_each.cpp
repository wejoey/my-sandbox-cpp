#include <algorithm>
#include <chrono>
#include <cstdint>
#include <execution>
#include <iostream>
#include <random>
#include <vector>

#define PARALLEL 1

#ifdef PARALLEL
// namespace execution = std::execution;
#else
enum class execution { seq, unseq, par_unseq, par };
#endif

void measure([[maybe_unused]] auto policy, std::vector<std::uint64_t> v) {
  const auto start = std::chrono::steady_clock::now();
#ifdef PARALLEL
  std::sort(policy, v.begin(), v.end());
#else
  std::sort(v.begin(), v.end());
#endif
  const auto finish = std::chrono::steady_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(finish -
                                                                     start)
            << '\n';
};

int main() {
  std::vector<std::uint64_t> v(1'000'000);
  std::mt19937 gen{std::random_device{}()};
  std::ranges::generate(v, gen);

  measure(std::execution::seq, v);
  measure(execution::unseq, v);
  measure(execution::par_unseq, v);
  measure(execution::par, v);
}