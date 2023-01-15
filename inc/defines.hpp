#ifndef DEFINES_HPP
# define DEFINES_HPP

# define FT 
# define CPP	    1
# define CPP98		__cplusplus >= 199711L
# define CPP11		__cplusplus >= 201103L
# define CPP14		__cplusplus >= 201402L
# define CPP17		__cplusplus >= 201703L
# define CPP20		__cplusplus >= 202002L
# define CPP23		__cplusplus >= 202003L
# define PRECPP98	__cplusplus <  199711L
# define PRECPP11	__cplusplus <  201103L
# define PRECPP14	__cplusplus <  201402L
# define PRECPP17	__cplusplus <  201703L
# define PRECPP20	__cplusplus <  202002L
# define PRECPP23	1


# if PRECPP11
#  ifndef constexpr
#   define constexpr
#  endif // constexpr
#  ifndef override
#   define override
#  endif // override
#  ifndef noexcept
#   define noexcept throw()
#  endif // noexcept
#  ifndef NOEXCEPT
#   define NOEXCEPT(value) throw(value)
#  endif // noexcept()
# else
#  ifndef NOEXCEPT
#   define NOEXCEPT(value) noexcept(value)
#  endif
# endif

# if PRECPP20
# ifndef LIKELY
#  define LIKELY(expr) (__builtin_expect((expr), 1))
# else 
#  ifndef LIKELY
#   define LIKELY(expr) (expr) [[likely]]
#  endif
# endif /* LIKELY */

# endif

# ifndef PANIC_ON
#  define PANIC_ON(expr, msg)                       \
    do {                                            \
        if ((expr) == 0) {                          \
            std::cerr << __FILE__ << ":"            \
                << __LINE__ << " "                  \
                << (msg) << std::endl;              \
            std::abort();                           \
        }                                           \
   } while (false)                              
# endif

#endif
