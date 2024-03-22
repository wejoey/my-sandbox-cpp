#include <iostream>
#include <type_traits>

#ifdef _DEBUG
constexpr bool debug_mode = true;
#else
constexpr bool debug_mode = false;
#endif

// https://blog.tartanllama.xyz/if-constexpr/
template <typename T>
auto get_value(T t) {
    if constexpr (std::is_pointer_v<T>) return *t;
    else return t;
}

template <typename T>
constexpr bool isIntegral() {
  return static_cast<bool>(std::is_integral<T>::value);
}


template <typename T>
constexpr bool isFloatingPoint() {
  return static_cast<bool>(std::is_floating_point<T>::value);
}


int main() {

    auto x = get_value(1);

    if constexpr (debug_mode) {
        std::cout << "*Debug*";
    }

    std::cout << isIntegral<int>();
    std::cout << isFloatingPoint<int>();

}