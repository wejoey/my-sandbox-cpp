#include <iostream>
#include <optional>

int main() {

  auto FindPlayerNumber =
      [](std::string_view playerName) -> std::optional<int> {
    return playerName == "Jackie Robinson" ? std::make_optional(42)
                                           : std::nullopt;
  };
  {
    auto playerFound = FindPlayerNumber("Rafael Devers").has_value();
    auto number = FindPlayerNumber("Rafael Devers").value_or(0);
    std::cout << playerFound << number;
  }
  {
    auto playerFound = FindPlayerNumber("Jackie Robinson").has_value();
    auto number = FindPlayerNumber("Jackie Robinson").value_or(0);
    std::cout << playerFound << number;
  }
}