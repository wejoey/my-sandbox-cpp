#include <algorithm>
#include <iostream>

int main() {
  {

    auto addition = [](int x, int y) constexpr { return x + y; };
    static_assert(addition(3, 5) == 8);
  }
  {
    constexpr int addition(int x, int y) {
      return [x, y] { return x + y; }();
    }
    static_assert(addition(3, 5) == 8);
  }
}
