#include <algorithm>
#include <chrono>
#include <execution>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std::literals;

// inspired from https://en.cppreference.com/w/cpp/algorithm/reduce
// clang++ -std=c++17 ./execution.cpp -ltbb -O3 -o release/execution.out; ./release/execution.out

int main() {

  {

    std::vector<int> v = {1, 8, 0, 4, 7, 2, 3, 9, 5, 6};

    {
      const auto t1 = std::chrono::high_resolution_clock::now();
      std::sort(std::execution::seq, v.begin(), v.end());
      const auto t2 = std::chrono::high_resolution_clock::now();
      const std::chrono::duration<double, std::milli> ms = t2 - t1;
      std::cout << "v[10] sort seq: " << ms.count() << " ms\n";
    }
    {
      const auto t1 = std::chrono::high_resolution_clock::now();
      std::sort(std::execution::par, v.begin(), v.end());
      const auto t2 = std::chrono::high_resolution_clock::now();
      const std::chrono::duration<double, std::milli> ms = t2 - t1;
      std::cout << "v[10] sort par: " << ms.count() << " ms\n";
    }
  }
  {
    std::vector<int> v2 = {1, 8, 0, 4, 7, 2, 3, 9, 5, 6};
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 999999);

    for (int i = 0; i < 999999; ++i) {
      v2.emplace_back(dist(rng));
    }

    {
      const auto t1 = std::chrono::high_resolution_clock::now();
      std::sort(std::execution::seq, v2.begin(), v2.end());
      const auto t2 = std::chrono::high_resolution_clock::now();
      const std::chrono::duration<double, std::milli> ms = t2 - t1;
      std::cout << "v[1M] sort seq: " << ms.count() << " ms\n";
    }
    {
      const auto t1 = std::chrono::high_resolution_clock::now();
      std::sort(std::execution::par, v2.begin(), v2.end());
      const auto t2 = std::chrono::high_resolution_clock::now();
      const std::chrono::duration<double, std::milli> ms = t2 - t1;
      std::cout << "v[1M] sort par: " << ms.count() << " ms\n";
    }
  }
}