#include <iostream>
#include "integral_constant.hpp"
// #include <type_traits>

#define SHOW(value, res) \
    std::cout << #res << " == " << #value << " ? " << (res == value) << std::endl

namespace on = ft;

int main(void) {
    SHOW((on::integral_constant<bool, true>::value), true);
    SHOW((on::integral_constant<bool, false>::value), false);
}
