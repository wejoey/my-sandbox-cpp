#include <functional>
#include <iostream>
#include <type_traits>
#include <variant>

void testBasic() {
  auto Print = [](const auto &player) {
    if (std::holds_alternative<int>(player)) {
      std::cout << std::get<int>(player) << '\n';
    } else if (std::holds_alternative<std::string>(player)) {
      std::cout << std::get<std::string>(player) << '\n';
    }
  };

  std::variant<int, std::string> player{"Jackie Robinson"};
  Print(player);
  player = 42; // Robinson's jersey number
  Print(player);
}

void testTryCatch() {

  std::variant<int, std::string> player{"Jackie Robinson"};
  try {
    std::get<int>(player);
  } catch (const std::bad_variant_access &ex) {
    std::cout << ex.what() << '\n';
  }
}

void testVisit() {
  std::variant<int, std::string> player{""};

  struct MyVisitor {
    void operator()(int playerNumber) const {
      std::cout << "playerNumber: " << playerNumber << "\n";
    }
    void operator()(const std::string &playerName) const {
      std::cout << "playerName: " << playerName << "\n";
    }
  };

  player = "Jackie Robinson";
  std::visit(MyVisitor{}, player);
  player = 42;
  std::visit(MyVisitor{}, player);
}

int main() {
  // testBasic();
  // testTryCatch();
  testVisit();
}