#include <iostream>
#include "is_integral.hpp"
#include <type_traits>

#define SHOW(value) \
    std::cout << (#value) << " == " << (value) << std::endl

namespace on = ft;


class A { };

int main(void) {
    // on::is_integral<A> a;
    // std::cout << on::is_integral<A>::value;
    SHOW(ft::is_integral<A>::value);
    SHOW(ft::is_integral<bool>::value);
    SHOW(ft::is_integral<char>::value);
    SHOW(ft::is_integral<char16_t>::value);
    SHOW(ft::is_integral<char32_t>::value);
    SHOW(ft::is_integral<wchar_t>::value);
    SHOW(ft::is_integral<short>::value);
    SHOW(ft::is_integral<int>::value);
    SHOW(ft::is_integral<long>::value);
    SHOW(ft::is_integral<long long>::value);

    return (0);
}
