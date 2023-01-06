#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft {
    template<class T, class Allocator = std::allocator<T> > class vector {
    public:

        vector(void);
        explicit vector(const vector<T> &obj);
    };
}


#endif // VECTOR_HPP