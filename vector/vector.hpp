#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>
# include <exception>
# include "defines.hpp"

namespace ft {

    namespace ee = std;

# ifdef FT 
#  include "enable_if.hpp"
#  include "is_integral.hpp"
# endif

    template<class T, class Allocator = std::allocator<T> >
    class vector {
    public:
        typedef T                                               value_type;
        typedef const T                                         const_value_type;
        typedef Allocator                                       allocator_type; 
        typedef std::size_t                                     size_type;
        typedef std::ptrdiff_t                                  difference_type;
        typedef value_type&                                     reference;
        typedef const value_type&                               const_reference;
        typedef ee::iterator<
            std::random_access_iterator_tag, value_type>        iterator;
        typedef ee::iterator<
            std::random_access_iterator_tag, const_value_type>  const_iterator;
        typedef ee::reverse_iterator<iterator>                 reverse_iterator;
        typedef ee::reverse_iterator<const_iterator>           const_reverse_iterator;

/* # if PRECPP11 */

        typedef typename Allocator::pointer          pointer;
        typedef typename Allocator::const_pointer    const_pointer;

        // todo iterator
/* # endif */
// # elif CHECK_STANDARD(CPP20)

//  # endif

    private:

        difference_type difference;
        allocator_type  allocator;
        pointer         _begin;
        pointer         _end;

        void cpy(pointer dst, pointer src, size_type count) {
            pointer iterDst = dst;
            pointer iterSrc = src;

            for (size_type i = 0; i < count; ++i) {
                allocator.construct(iterDst, *iterSrc);
                ++iterDst;
                ++iterSrc;
            }
        }

        void cpy(pointer dst, const_reference value, size_type count) {
            pointer iter = dst;

            for (size_type i = 0; i < count; ++i) {
                allocator.construct(iter, value);
                ++iter;
            }
        }

        template <class InputIt,
                 typename ee::enable_if<!ee::is_integral<InputIt>::value, InputIt>::type>
        void cpy(pointer dst, InputIt itBegin, InputIt itEnd) {
            for (; itBegin != itEnd; ++itBegin) {
                allocator.construct(dst++, *itBegin);
            }
        }

        void init(size_type count, const_reference value) {
            difference = count;
            _begin = allocator.allocate(count);
            _end = _begin + difference;
            cpy(_begin, value, count);
        }

        template <class InputIt,
                 typename ee::enable_if<!ee::is_integral<InputIt>::value, InputIt> >
        void init(InputIt first, InputIt last) {
            difference = std::distance(first, last);
            _begin = allocator.allocate(difference);
            _end = _begin + difference;
            cpy(_begin, first, last);
        }

        void clean() {
            for (pointer it = _begin; it != _end; ++it)
                allocator.destroy(it);
            allocator.deallocate(_begin, difference);
        }


    public:

        constexpr vector()
        :   difference(0),
            _begin(NULL),
            _end(NULL) { }

        constexpr explicit vector(const allocator_type &alloc) noexcept
        :   difference(0),
            allocator(alloc),
            _begin(NULL),
            _end(NULL) { }

        explicit vector(size_type count,
                        const value_type &value = T(),
                        const allocator_type &alloc = allocator_type()) 
        :   difference(0),
            allocator(alloc),
            _begin(NULL),
            _end(NULL) {
            if (count > 0)
                init(count, value);
        }

        // constexpr explicit vector( size_type count, const Allocator& alloc = Allocator() ) // (since C++20)

        template<class InputIt>
        constexpr vector(InputIt first, InputIt last, const allocator_type &alloc = allocator_type())
        :   difference(0),
            allocator(alloc),
            _begin(NULL),
            _end(NULL) {
            init(first, last);
        }

        constexpr vector(const vector &other) 
        :   difference(other.difference),
            _begin(NULL),
            _end(NULL) {
            init(other.begin(), other.end());
        }

        // constexpr vector( const vector& other, const Allocator& alloc );  // (since C++20)
        // constexpr vector( vector&& other ) noexcept; // (since C++20)
        // constexpr vector( vector&& other, const Allocator& alloc );  // (since C++20)
        // constexpr vector( std::initializer_list<T> init, const Allocator& alloc = Allocator() ); // (since C++20)

        ~vector(void) {
            clean();
        }

        constexpr vector& operator=(const vector &other) {
            clean();
            init(other.begin(), other.end());
        }

        void assign(size_type count, const T &value) {
            clean();
            init(count, value);
        }

        template< class InputIt >
        void assign(InputIt first, InputIt last) {
            clean();
            init(first, last);
        }

        allocator_type get_allocator(void) const {
            return (allocator);
        }

        reference at(size_type pos) {
            if (pos >= difference)
                throw std::out_of_range("vector<..> out_of_range");
            return (*(_begin + pos));
        }

        const_reference at(size_type pos) const {
            if (pos >= difference)
                throw std::out_of_range("vector<..> out_of_range");
            return (*(_begin + pos));
        }
 
        constexpr reference operator[](size_type pos) {
            return (*(_begin + pos));
        }

        constexpr const_reference operator[]( size_type pos ) const {
            return (*(_begin + pos));
        }

        constexpr reference front() {
            return (*_begin);
        }

        constexpr const_reference front() const {
            return (*_begin);
        }

        constexpr reference back() {
            return (*(_end - 1));
        }

        constexpr const_reference back() const {
            return (*(_end - 1));
        }


        value_type *data() {
            if (difference == 0)
                return (NULL);
            return (_begin);
        }

        const_value_type *data() const {
            if (difference == 0)
                return (NULL);
            return (_begin);
        }

        iterator begin() { return (iterator(_begin)); }
        const_iterator begin() const { return (iterator(_begin)); }

        iterator end() { return (iterator(_end)); }
        const_iterator end() const { return (iterator(_end)); }

        reverse_iterator rbegin() { return (reverse_iterator(_begin)); }
        const_reverse_iterator rbegin() const { return (reverse_iterator(_begin)); }

        reverse_iterator rend() { return (reverse_iterator(_end)); }
        const_reverse_iterator rend() const { return (reverse_iterator(_end)); }

        
    };
}

#endif // VECTOR_HPP
