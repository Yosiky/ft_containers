#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include <stdint.h>
# include "defines.hpp"
# include "integral_constant.hpp"

namespace ft {

    typedef uint_least16_t char16_t;
    typedef uint_least32_t char32_t;

    template <class T> struct is_integral { ft::false_type value; };

    template <> struct is_integral<bool>        { ft::true_type value; };
    template <> struct is_integral<char>        { ft::true_type value; };
    template <> struct is_integral<char16_t>    { ft::true_type value; };
    template <> struct is_integral<char32_t>    { ft::true_type value; };
    template <> struct is_integral<wchar_t>     { ft::true_type value; };
    template <> struct is_integral<short>       { ft::true_type value; };
    template <> struct is_integral<int>         { ft::true_type value; };
    template <> struct is_integral<long>        { ft::true_type value; };
    template <> struct is_integral<long long>   { ft::true_type value; };

}

#endif