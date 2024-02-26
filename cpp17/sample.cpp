#include <algorithm>
#include <iostream>
#include <random>
#include <string>

int main()
{
    // From https://github.com/AnthonyCalandra/modern-cpp-features/blob/master/CPP17.md
    const std::string ALLOWED_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    std::string guid;
    // Sample 8 characters from ALLOWED_CHARS.
    std::sample(ALLOWED_CHARS.begin(), ALLOWED_CHARS.end(), std::back_inserter(guid),
                8, std::mt19937{ std::random_device{}() });

    std::cout << guid; // ex: gwzGS468
}