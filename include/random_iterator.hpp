#ifndef RANDOM_ACCESS_ITERATOR_HPP 
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iterator>
# include "defines.hpp"

namespace ft {
    
    template <class T>
    class wrapper_iterator: public std::iterator<std::random_access_iterator_tag, T> {
    
    public:
        typedef std::random_access_iterator_tag tag;
        typedef std::iterator<tag, T>           iterator_traits;

        typedef typename iterator_traits::iterator_category  iterator_category;
        typedef typename iterator_traits::value_type         value_type;
        typedef typename iterator_traits::difference_type    difference_type;
        typedef typename iterator_traits::pointer            pointer;
        typedef typename iterator_traits::reference          reference;

    private:
        typedef wrapper_iterator<T>             self_type;
        pointer ptr;

    private:
        wrapper_iterator(void);

    public:

        pointer base(void) const {
            return (ptr);
        }
        
    
        wrapper_iterator(pointer value)
        : ptr(value) { }

        template <class Up>
        wrapper_iterator(const wrapper_iterator<Up> &other)
        : ptr(other.base()) { }

        self_type &operator=(const self_type &other) {
            ptr = other.ptr;
        } 

        ~wrapper_iterator(void) { }
    
    // LegacyIterator
    
        value_type &operator*(void) {
            return (*ptr);
        }
    
        self_type &operator++(void) {
            ++ptr;
            return (*this);
        }
    
    // EqualityComparable
    
        bool operator==(const self_type &other) const {
            return (this->ptr == other.ptr);
        }
    
    // LegacyInputIterator
    
        bool operator!=(const self_type &other) const {
            return (this->ptr != other.ptr);
        }
    
        reference operator*(void) const {
            return (*ptr);
        }
    
        reference operator->(void) const {
            return (*ptr);
        }
    
    // LegacyForwardIterator
    
        self_type operator++(int) {
            self_type copy = *this;
    
            ++ptr;
            return (copy);
        }
    
    // LegacyBidirectionalIterator
        
        self_type &operator--() {
            --ptr;
            return (*this);
        }

        self_type operator--(int) {
            self_type copy = *this;

            --ptr;
            return (*this);
        }
    
    // LegacyRandomAccessIterator
    
        self_type &operator+=(difference_type n) {
            ptr += n;
            return (*this);
        }
    
        self_type operator+(difference_type n) const {
            return (self_type(ptr + n));
        }

        friend self_type operator+(difference_type n, const self_type &other) {
            return (other + n);
        }

        self_type &operator-=(difference_type n) {
            ptr -= n;
            return (*this);
        }

        self_type operator-(difference_type n) {
            return (self_type(ptr - n));
        }

        difference_type operator-(const self_type &a) const {
            return (this->ptr - a.ptr);
        }

        reference operator[](difference_type n) const {
            return (*(ptr + n));
        }

        bool operator<(const self_type &other) const {
            return (this->ptr < other.ptr);
        }

        bool operator>(const self_type &other) const {
            return (this->ptr > other.ptr);
        }
    
        bool operator>=(const self_type &other) const {
            return (this->ptr >= other.ptr);
        }

        bool operator<=(const self_type &other) const {
            return (this->ptr <= other.ptr);
        }

    };

    template <class T>
    class wrapper_reverse_iterator {

        typedef T                               iterator;
        typedef wrapper_reverse_iterator<T>     self_type;
        typedef typename iterator::value_type   value_type;
        typedef typename iterator::pointer      pointer;
        typedef typename iterator::reference    reference;
        typedef typename iterator::difference_type  difference_type;

        iterator it;

        wrapper_reverse_iterator(void);

    public:

        wrapper_reverse_iterator(pointer other)
        : it(other) { }

        wrapper_reverse_iterator(iterator other) 
        : it(other) { }

        template <class Up>
        wrapper_reverse_iterator(const wrapper_reverse_iterator<Up> &other)
        : it(other.it.base()) { }

        self_type &operator=(const self_type &other) {
            it = other.it;
        }

        self_type &operator++() {
            --it;
            return (*this);
        }

        self_type &operator++(int) {
            self_type copy = *this;
            
            --it;
            return (copy);
        }

        self_type &operator--() {
            ++it;
            return (*this);
        }

        self_type operator--(int) {
            self_type copy = *this;

            ++it;
            return (*this);
        }

    // EqualityComparable
    
        bool operator==(const self_type &other) const {
            return (this->it == other.it);
        }
    
    // LegacyInputIterator
    
        bool operator!=(const self_type &other) const {
            return (this->it != other.it);
        }
    
        reference operator*(void) const {
            return (*it);
        }
    
        reference operator->(void) const {
            return (*it);
        }
    
    // LegacyRandomAccessIterator
    
        self_type &operator+=(difference_type n) {
            it += n;
            return (*this);
        }
    
        self_type operator+(difference_type n) const {
            return (self_type(it + n));
        }

        friend self_type operator+(difference_type n, const self_type &other) {
            return (self_type(other.it + n));
        }

        self_type &operator-=(difference_type n) {
            it -= n;
            return (*this);
        }

        difference_type operator-(const self_type &a) const {
            return (this->it - a.it);
        }

        reference operator[](difference_type n) const {
            return (*(it + n));
        }

        bool operator<(const self_type &other) const {
            return (this->it < other.it);
        }

        bool operator>(const self_type &other) const {
            return (this->it > other.it);
        }
    
        bool operator>=(const self_type &other) const {
            return (this->it >= other.it);
        }

        bool operator<=(const self_type &other) const {
            return (this->it <= other.it);
        }




    };

}

#endif
