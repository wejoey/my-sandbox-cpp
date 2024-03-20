#include <filesystem>
#include <iostream>

int main() {

    std::filesystem::path myDirectory{"/tmp/test/"};
    if (!std::filesystem::is_directory(myDirectory))
    {
        std::filesystem::create_directory(myDirectory);
    }
    std::filesystem::remove_all(myDirectory);
}