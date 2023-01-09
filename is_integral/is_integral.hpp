#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include <stdint.h>
# include "defines.hpp"
# include "integral_constant.hpp"

namespace ft {

    // typedef uint_least16_t char16_t;
    // typedef uint_least32_t char32_t;

    template <class T> struct is_integral : public ft::false_type { };

    template <> struct is_integral<bool>        : public ft::true_type { };
    template <> struct is_integral<char>        : public ft::true_type { };
    template <> struct is_integral<char16_t>    : public ft::true_type { };
    template <> struct is_integral<char32_t>    : public ft::true_type { };
    template <> struct is_integral<wchar_t>     : public ft::true_type { };
    template <> struct is_integral<short>       : public ft::true_type { };
    template <> struct is_integral<int>         : public ft::true_type { };
    template <> struct is_integral<long>        : public ft::true_type { };
    template <> struct is_integral<long long>   : public ft::true_type { };

}

#endif