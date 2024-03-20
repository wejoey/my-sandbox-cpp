#include <functional>
#include <iostream>

bool Reset1([[maybe_unused]] int i) { return true; } // Ok
[[nodiscard]] bool Reset2(int i) { return true; };   // Warning `i` is not used

void foo() { return; }
int main() {
  Reset1(42); // Ok
  Reset2(42); // Warning, can't discard the return value

  char pos{'c'};

  switch (pos) {
  case 'a':
    std::cout << 'a'; // Warning, is the fallthrough intentional ?
  case 'b':
    std::cout << 'b';
    [[fallthrough]]; // Ok
  default:
    std::cout << 'z';
  }
}