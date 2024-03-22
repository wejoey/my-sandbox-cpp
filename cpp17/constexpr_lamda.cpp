#include <algorithm>
#include <iostream>

constexpr int addition1(int x, int y) {
  return [x, y] { return x + y; }();
}

int main() {
  static_assert(addition1(6, 2) == 8);

  auto addition2 = [](int x, int y) constexpr { return x + y; };
  static_assert(addition2(3, 5) == 8);
}
