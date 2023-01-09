#ifndef INTEGRAL_CONSTANT_HPP
# define INTEGRAL_CONSTANT_HPP

# include "defines.hpp"

namespace ft {

    template <class T, T v>
    struct integral_constant {
        typedef T                           value_type;
        typedef ft::integral_constant<T, v> type;

        constexpr static const T value = v;

        constexpr operator value_type() const noexcept { return value; }
    };

    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

}

#endif 