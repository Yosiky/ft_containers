#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>

# include "defines.hpp"

namespace ft {
    template<class T, class Allocator = std::allocator<T> > class vector {
        typedef T                                       value_type;
        typedef Allocator                               allocator_type; 
        typedef std::size_t                             size_type;
        typedef std::ptrdiff_t                          difference_type;
        typedef value_type&                             reference;
        typedef const value_type&                       const_reference;
        typedef std::reverse_iterator<iterator>         reverse_iterator;
        typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;

# if PRECPP11


#  define override
#  define constexpr

        typedef Allocator::pointer          pointer;
        typedef Allocator::const_pointer    const_pointer;
        // todo iterator
# endif
// # elif CHECK_STANDARD(CPP20)

//  # endif

        difference_type difference;
        allocator_type  allocator;
        pointer         begin;
        pointer         end;

        void cpy(pointer dst, pointer src, size_type count) {
            pointer iterDst = dst;
            pointer iterSrc = src;

            for (size_type i = 0; i < count; ++i) {
                allocator.construct(iterDst, *iterSrc);
                iterDst += sizeof(value_type);
                iterSrc += sizeof(value_type);
            }
        }

        void cpy(pointer dst, const_reference value, size_type count) {
            pointer iter = dst;

            for (size_type i = 0; i < count; ++i) {
                allocator.construct(iter, value);
                iter += sizeof(value_type);
            }
        }

        template <class InputIt>
        void cpy(pointer dst, InputIt itBegin, InputIt itEnd) {
            for (; itBegin != itEnd; ++itBegin) {
                allocator.construct(dst, *itBegin);
            }
        }

        void init(size_type count, const_reference value) {
            begin = allocator.allocate(count);
            cpy(begin, value, count);
        }

        template <class InputIt>
        void init(std::enable_if<true, InputIt>::type first, InputIt last) {
            difference_type count = std::distance(first, last);

            begin = allocator.allocate(count);
            cpy(begin, first, last);
            
        }

        template <class T>
        class is_integral {
            typedef value std::false_type;
        }

        class is_integral<int> {
            typedef value std::true_type;
        }


    public:
        constexpr vector() NOEXCEPT(NOEXCEPT(Allocator()));
        :   difference(0),
            allocator(allocator_type()),
            begin(NULL),
            end(NULL)
        { }

        constexpr explicit vector(const allocator_type &alloc) noexcept
        :   difference(0),
            allocator(alloc),
            begin(NULL),
            end(NULL)
        { }

        explicit vector(size_type count,
                        const value_type &value = T(),
                        const allocator_type &alloc = allocator_type()) 
        :   difference(0),
            allocator(alloc) 
            begin(NULL),
            end(NULL) {
            if LIKELY(count > 0)
                init(count, value)
        }

        // constexpr explicit vector( size_type count, const Allocator& alloc = Allocator() ) // (since C++20)

        template<class InputIt>
        constexpr vector(InputIt first, InputIt last, const allocator_type &alloc = allocator_type());
        :   difference(0),
            allocator(alloc),
            begin(NULL),
            end(NULL) {
            init(first, last);
        }

        constexpr vector(const vector &other) {

        }

        // constexpr vector( const vector& other, const Allocator& alloc );  // (since C++20)
        // constexpr vector( vector&& other ) noexcept; // (since C++20)
        // constexpr vector( vector&& other, const Allocator& alloc );  // (since C++20)
        // constexpr vector( std::initializer_list<T> init, const Allocator& alloc = Allocator() ); // (since C++20)

        ~vector() {

        }

        vector& operator=( const vector& other );
        void assign( size_type count, const T& value );
        template< class InputIt >
        void assign( InputIt first, InputIt last );
        allocator_type get_allocator() const;
        reference at( size_type pos );
        const_reference at( size_type pos ) const;
    };
}

#endif // VECTOR_HPP