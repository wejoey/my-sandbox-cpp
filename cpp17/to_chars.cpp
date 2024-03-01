#include <array>
#include <charconv>
#include <iostream>
#include <string_view>
#include <system_error>

int main() {
  std::array<char, 5> resultBuffer{};
  std::cout << "Conversion 12: ";
  {
    std::to_chars_result ret = std::to_chars(resultBuffer.data(),
                             resultBuffer.data() + resultBuffer.size(), 12);

    if (ret.ec == std::errc()) {
      std::cout << std::string_view(resultBuffer.data()) << '\n';
    } else {
      std::cout << std::make_error_code(ret.ec).message() << '\n';
    }
  }
  std::cout << "Conversion 12.34f: ";
  {
    auto ret = std::to_chars(resultBuffer.data(),
                             resultBuffer.data() + resultBuffer.size(), 12.34f);

    if (ret.ec == std::errc()) {
      std::cout << std::string_view(resultBuffer.data()) << '\n';
    } else {
      std::cout << std::make_error_code(ret.ec).message() << '\n';
    }
  }
  std::cout << "Conversion 12.3456789: ";
  {
    auto ret = std::to_chars(resultBuffer.data(),
                             resultBuffer.data() + resultBuffer.size(), 12.3456789);
    if (ret.ec == std::errc()) {
      std::cout << std::string_view(resultBuffer.data()) << '\n';
    } else {
      std::cout << std::make_error_code(ret.ec).message() << '\n';
    }
  }

}