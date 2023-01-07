#ifndef INTEGRAL_CONSTANT_HPP
# define INTEGRAL_CONSTANT_HPP

# include "defines.hpp"

namespace ft {

    template <class T, T v = T()>
    struct integral_constant {
# if CPP11
        constexpr static T value = v;
# else
        constexpr static T value;
# endif
    };

# if PRECPP11
    template <class T, T v>
    T integral_constant<T, v>::value = v;
# endif

    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

}

#endif 