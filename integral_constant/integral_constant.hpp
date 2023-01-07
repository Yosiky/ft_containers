#ifndef INTEGRAL_CONSTANT_HPP
# define INTEGRAL_CONSTANT_HPP

# include "defines.hpp"

namespace ft {

    template <class T, T v = T()>
    struct integral_constant {
# if CPP11
        constexpr T value = v;
# else
        constexpr T value; 

        integral_constant(void) : value(v) { }
        integral_constant(const integral_constant<T> &newValue) : value(newValue.value) { }
        ~integral_constant(void);

        integral_constant<T> &operator=(const integral_constant<T> &newValue) {
            value = newValue.value;
            return (*this);
        }

# endif
    };

    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

}

#endif 