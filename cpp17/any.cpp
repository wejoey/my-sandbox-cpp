#include <any>
#include <iostream>
#include <string>
#include <string_view>
#include <sys/types.h>
#include <variant>
#include <vector>

void testBasic() {
  std::any myAnyValue{10};
  std::cout << std::any_cast<int>(myAnyValue) << "\n";

  std::string str{"I'm a string"};
  myAnyValue = str;
  std::cout << std::any_cast<std::string&>(myAnyValue) << "\n";
}

struct ALargeObject{
    std::vector<std::string> v;
    ALargeObject(ALargeObject &&) = delete;
    //ALargeObject& operator=(const ALargeObject&) = default;
    ALargeObject(const ALargeObject&) = default;
    ALargeObject() = default;
};

void testSize() {

  std::any myAnyValue{10};
  std::cout << "myAnyValue sizeof: " << sizeof(myAnyValue) << "\n";

  myAnyValue = 3.14159;
  std::cout << "myAnyValue sizeof: " << sizeof(myAnyValue) << "\n";

  ALargeObject aLargeObject;
  aLargeObject.v.emplace_back("test");
  myAnyValue = aLargeObject;
  auto ref = std::any_cast<ALargeObject&>(myAnyValue);
  std::cout << "myAnyValue sizeof: " << sizeof(myAnyValue) << "\n";
  auto copy = std::any_cast<ALargeObject>(myAnyValue);
  std::cout << "myAnyValue sizeof: " << sizeof(myAnyValue) << "\n";


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
  //testBasic();
  testSize();
}