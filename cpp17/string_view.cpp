#include <algorithm>
#include <iostream>
#include <string_view>

using std::operator""s;
using std::operator""sv;

void PrintString(const std::string& aConstRefString, // requires to be in a std::string
                   std::string_view aStringView)     // a view (ptr+len) only
{
    std::cout << "str: " << aConstRefString << aConstRefString.size() << "\n";
    std::cout << "strview: " << aStringView << aStringView.size() << "\n";
}

void CallPrintString(){
    const std::string      str{"a string"};
    const std::string_view strview{"a string_view"};

    PrintString(str.substr(2),       // copy the string
                strview.substr(2));  // copy only the updated ptr+len
}

#if 0
void LiteralsOperator() {
  // the “s1” literal is used to create a std::string which is destroyed at the
  // end // of the expression, then the string_view `sv1` will point nowhere
  std::string_view sv1 = "s1"s; // bad

  // the new “”sv c++17 operator create a std::string_view that point to the
  // string literal itself in the static storage
  std::string_view sv2 = "s2"sv; // ok

  // that’s why sv3 doesn’t compile, but sv4 does!

  // constexpr std::string_view sv3 = "s3"s;
  constexpr std::string_view sv4 = "s4"sv;

  std::cout << sv1 << "\n";
  std::cout << sv2 << "\n";
}
#endif

int main() {
  PrintString("a string"s, "a string_view"sv);
  CallPrintString();
  //LiteralsOperator();
}