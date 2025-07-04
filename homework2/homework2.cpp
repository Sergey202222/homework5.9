#include "big_integer.hpp"
#include <iostream>

int main()
{
    auto number1 = integer::big_integer("114575");
    auto number2 = integer::big_integer("78524");
    auto result = number1 + number2;
    std::cout << result;
    auto number3 = integer::big_integer("114575");
    auto result2 = number3 * 800;
    std::cout << '\n' << result2;
    return EXIT_SUCCESS;
}