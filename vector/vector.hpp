#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace ft {
    template<class T, class Allocator = std::allocator<T> > class vector {
    public:
        vector();
        explicit vector( const Allocator& alloc );
        explicit vector( size_type count,
                 const T& value = T(),
                 const Allocator& alloc = Allocator());
        template< class InputIt >
vector( InputIt first, InputIt last,
        const Allocator& alloc = Allocator() );
        vector( const vector& other );
        ~vector();

        vector& operator=( const vector& other );
        void assign( size_type count, const T& value );
        template< class InputIt >
void assign( InputIt first, InputIt last );
allocator_type get_allocator() const;
    };
}


#endif // VECTOR_HPP