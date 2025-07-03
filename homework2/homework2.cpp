#include "big_integer.hpp"
#include <iostream>

int main()
{
    auto number1 = big_integer::big_integer("114575");
    auto number2 = big_integer::big_integer("78524");
    auto result = number1 + number2;
    std::cout << result;
    return EXIT_SUCCESS;
}