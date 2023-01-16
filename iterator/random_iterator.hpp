#ifndef RANDOM_ACCESS_ITERATOR_HPP 
# define RANDOM_ACCESS_ITERATOR_HPP

# include <iterator>
# include "defines.hpp"

namespace ft {
    
    template <class T>
    class iterator_base: public std::iterator<std::random_access_iterator_tag, T> {
    
    public:

        typedef std::random_access_iterator_tag tag;
        typedef std::iterator<tag, T>           iterator_traits;
        typedef iterator_base<T>                self_type;

        typedef typename iterator_traits::iterator_category  iterator_category;
        typedef typename iterator_traits::value_type         value_type;
        typedef typename iterator_traits::difference_type    difference_type;
        typedef typename iterator_traits::pointer            pointer;
        typedef typename iterator_traits::reference          reference;

    private:
        pointer ptr;

        iterator_base(void);

    public:
    
        explicit iterator_base(pointer value)
        : ptr(value) { }

        iterator_base(const self_type &other)
        : ptr(other.ptr) { }

        self_type &operator=(const self_type &other) {
            ptr = other.ptr;
        } 

        ~iterator_base(void) { }
    
    // LegacyIterator
    
        value_type &operator*() {
            return (*ptr);
        }
    
        self_type &operator++() {
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
    
        reference operator*() const {
            return (*ptr);
        }
    
        reference operator->() const {
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
    
        self_type operator=(int) {
            self_type copy = *this;
    
            --ptr;
            return (copy);
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
    class wrapper_iterator: public iterator_base<T> {

            typedef iterator_base<T> parent;
            typedef typename parent::value_type     value_type;
            typedef typename parent::pointer        pointer;


            wrapper_iterator(void);

        public:

            explicit wrapper_iterator(pointer other)
            : parent(other) { }

            wrapper_iterator(const wrapper_iterator<value_type> &other)
            : parent(other) { }

            wrapper_iterator<value_type> &operator=(
                    const wrapper_iterator<value_type> &other) {
                parent::operator=(other);
            }
    };

    template <class T>
    class wrapper_reverse_iterator: public iterator_base<T> {

            typedef iterator_base<T> parent;
            typedef typename parent::value_type     value_type;
            typedef typename parent::pointer        pointer;
            typedef wrapper_reverse_iterator<T>     self_type;

            wrapper_reverse_iterator(void);

        public:

            explicit wrapper_reverse_iterator(pointer other)
            : parent(other) { }

            wrapper_reverse_iterator(const self_type &other)
            : parent(other) { }

            self_type &operator=(const self_type &other) {
                parent::operator=(other);
            }

            self_type &operator++() {
                parent::operator--();
                return (*this);
            }

            self_type &operator++(int) {
                self_type copy = *this;
                
                parent::operator--();
                return (copy);
            }

            self_type &operator--() {
                parent::operator++();
                return (*this);
            }

            self_type operator--(int) {
                self_type copy = *this;

                parent::operator++();
                return (*this);
            }

    };

}

#endif
