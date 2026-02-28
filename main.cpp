#include <format>
#include <iostream>
#include <string>

int main() {
    std::string test = std::format("Hello, {}!", "C++20");
    std::cout << test << std::endl;
    return 0;
}
