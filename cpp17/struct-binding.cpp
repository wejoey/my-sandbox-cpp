#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>

namespace CGL::CGLL {}
int main() {
  std::map<int, int> myMap;
  for (int i = 0; i < 100; ++i) {
    myMap.insert(std::make_pair(i, i + 100));
  }

  for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    std::cout << it->first << "," << it->second << "\n";
  }

  for (const auto &[key, value] : myMap) {
    std::cout << key << "," << value << "\n";
  }

  int myArray[3] = {2, 8, 16};
  const auto [A, B, C] = myArray;
  assert(A == 2 && B == 8 && C == 16);
}