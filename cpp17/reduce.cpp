#include <algorithm>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std::literals;

// example from https://en.cppreference.com/w/cpp/algorithm/reduce

// sudo apt install libtbb-dev
//clang++ -std=c++17 ./reduce.cpp -ltbb -O3 -DPARALLEL -o release/reduce.out; ./release/reduce.out
//clang++ -std=c++17 ./reduce.cpp -O3 -o release/reduce.out; ./release/reduce.out
//
#if PARALLEL
#include <execution>
#define SEQ std::execution::seq,
#define PAR std::execution::par,
#else
#define SEQ
#define PAR
#endif

void example(){
  auto eval = [](auto fun) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    const auto [name, result] = fun();
    const auto t2 = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> ms = t2 - t1;
    std::cout << std::setw(28) << std::left << name << "sum: " << result
              << "\t time: " << ms.count() << " ms\n";
  };
  const std::vector<double> v(900'000'007, 0.01);

  eval([&v] {
    return std::pair{"std::accumulate (double)",
                     std::accumulate(v.cbegin(), v.cend(), 0.0)};
  });
  eval([&v] {
    return std::pair{"std::reduce (seq, double)",
                     std::reduce(SEQ v.cbegin(), v.cend())};
  });
  eval([&v] {
    return std::pair{"std::reduce (par, double)",
                     std::reduce(PAR v.cbegin(), v.cend())};
  });
}

void testSimple(){
  const std::vector<double> v(123'456'789, 0.1);
  auto sumAccumulate = std::accumulate(v.cbegin(), v.cend(), 0.0);
  auto sumReduce     = std::reduce(v.cbegin(), v.cend(), 0.0);
  std::cout << "sumAccumulate: " << sumAccumulate << "\nsumReduce: " << sumReduce;
}

int main() {

    testSimple();
}