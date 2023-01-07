#include <iostream>
#include "integral_constant.hpp"

#define SHOW(value, res) \
    std::cout << #res << " == " << #value << " ? " << (res == value) << std::endl

int main(void) {
    SHOW((ft::integral_constant<bool, true>::value), true);
    SHOW((ft::integral_constant<bool, false>::value), false);
}
