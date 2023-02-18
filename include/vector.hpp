#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <exception>
# include <limits>

# include "defines.hpp"
# include "random_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"

# define ADD_ELEMENT 2

namespace ft {
    
    template <class T, class Allocator = std::allocator<T> >
    class vector {
    public:
        typedef T                                               value_type;
        typedef const T                                         const_value_type;
        typedef Allocator                                       allocator_type; 
        typedef std::size_t                                     size_type;
        typedef std::ptrdiff_t                                  difference_type;
        typedef value_type&                                     reference;
        typedef const value_type&                               const_reference;
        typedef typename Allocator::pointer                     pointer;
        typedef typename Allocator::const_pointer               const_pointer;
        typedef wrapper_iterator<value_type>                       iterator;
        typedef wrapper_iterator<const_value_type>                 const_iterator;
        typedef wrapper_reverse_iterator<iterator>            reverse_iterator;
        typedef wrapper_reverse_iterator<const_iterator>      const_reverse_iterator;

/* # if PRECPP11 */


        // todo iterator
/* # endif */
// # elif CHECK_STANDARD(CPP20)

//  # endif

    private:

        size_type       sizeAllocMem;
        allocator_type  allocator;
        pointer         pArrBegin;
        pointer         pArrEnd;

        void copyContextFromBegin(pointer pArgDst, pointer pArgSrc, size_type argCount) {
            while (argCount-- > 0) {
                *(pArgDst++) = *(pArgSrc++);
            }
        }

        template <class InputIt>
        void copyContextFromBegin(pointer pArgDst, 
                typename enable_if<!is_integral<InputIt>::value, InputIt>::type argItBegin,
                InputIt argItEnd) {
            for (InputIt it = argItBegin; it != argItEnd; ++it)
                *(pArgDst++) = *it;
        }

        void copyContext(pointer pArgDst, size_type argCount, size_type argValueInit) {
            for (size_type i = 0; i < argCount; ++i) {
                pArgDst[i] = argValueInit;
            }
        }

        void copyContextFromEnd(pointer pArgDst, pointer pArgSrc, size_type argCount) {
            pArgDst += argCount;
            pArgSrc += argCount;
            while (argCount-- > 0) {
                *(--pArgDst) = *(--pArgSrc);
            }
        }

        template <class InputIt>
        void copyContextFromEnd(pointer pArgDst, 
                typename enable_if<!is_integral<InputIt>::value, InputIt>::type argItBegin,
                InputIt argItEnd) {
            pArgDst += std::distance(argItBegin, argItEnd);
            for (InputIt it = argItEnd - 1; it >= argItBegin; --it)
                *(--pArgDst) = *it;
        }

        void initMem(pointer pArgBegin, size_type argCount) {
            value_type value;

            while (argCount-- > 0) {
                allocator.construct(pArgBegin++, value);
            }
        }

        void cpy(pointer pArgDst, pointer pArgSrc, size_type argCount) {
            for (size_type i = 0; i < argCount; ++i) {
                allocator.construct(pArgDst++, *(pArgSrc++));
            }
        }

        void cpy(pointer pArgDst, size_type argCount, const_reference argValueInit) {
            for (size_type i = 0; i < argCount; ++i) {
                allocator.construct(pArgDst++, argValueInit);
            }
        }

        template <class InputIt>
        void cpy(pointer pArgDst, 
                typename enable_if<!is_integral<InputIt>::value, InputIt>::type argItBegin, 
                InputIt argItEnd) {
            for (; argItBegin != argItEnd; ++argItBegin) {
                allocator.construct(pArgDst++, *argItBegin);
            }
        }

        void init(size_type argCount, const_reference argValueInit) {
            sizeAllocMem = argCount;
            pArrBegin = allocator.allocate(sizeAllocMem);
            pArrEnd = pArrBegin + argCount;
            cpy(pArrBegin, argCount, argValueInit);
        }

        template <class InputIt>
        void init(
                typename enable_if<!is_integral<InputIt>::value, InputIt>::type argItBegin, 
                InputIt argItEnd) {
            difference_type diffPtr = std::distance(argItBegin, argItEnd);
            sizeAllocMem = diffPtr;
            pArrBegin = allocator.allocate(diffPtr);
            pArrEnd = pArrBegin + diffPtr;
            cpy(pArrBegin, argItBegin, argItEnd);
        }

        void clean() {
            for (pointer it = pArrBegin; it != pArrEnd; ++it)
                allocator.destroy(it);
            allocator.deallocate(pArrBegin, sizeAllocMem);
            pArrBegin = NULL;
            pArrEnd = NULL;
        }

        void cleanRange(pointer argStart, size_type argCount) {
            pointer end = argStart + argCount;

            for (; argStart != end; ++argStart) {
                allocator.destroy(argStart);
            }
        }

    public:



        constexpr vector()
        :   sizeAllocMem(0),
            allocator(),
            pArrBegin(NULL),
            pArrEnd(NULL) { }

        constexpr explicit vector(const allocator_type &argAllocator) noexcept
        :   sizeAllocMem(0),
            allocator(argAllocator),
            pArrBegin(NULL),
            pArrEnd(NULL) { }

        explicit vector(size_type argCount,
                        const value_type &argValueInit = T(),
                        const allocator_type &argAllocator = allocator_type()) 
        :   sizeAllocMem(0),
            allocator(argAllocator),
            pArrBegin(NULL),
            pArrEnd(NULL) {
            if (argCount > 0)
                init(argCount, argValueInit);
        }

        // constexpr explicit vector( size_type count, const Allocator& alloc = Allocator() ) // (since C++20)

        template<class InputIt>
        constexpr vector(
            typename enable_if<!is_integral<InputIt>::value, InputIt>::type argFirst, 
            InputIt argLast, 
            const allocator_type &argAllocator = allocator_type())
        :   sizeAllocMem(0),
            allocator(argAllocator),
            pArrBegin(NULL),
            pArrEnd(NULL) {
            init(argFirst, argLast);
        }

        constexpr vector(const vector &argOtherVector) {
            init(argOtherVector.begin(), argOtherVector.end());
        }

        // constexpr vector( const vector& other, const Allocator& alloc );  // (since C++20)
        // constexpr vector( vector&& other ) noexcept; // (since C++20)
        // constexpr vector( vector&& other, const Allocator& alloc );  // (since C++20)
        // constexpr vector( initializer_list<T> init, const Allocator& alloc = Allocator() ); // (since C++20)

        ~vector(void) {
            clean();
        }

        constexpr vector& operator=(const vector &argOtherVector) {
            clean();
            init(argOtherVector.begin(), argOtherVector.end());
            return (*this);
        }

        allocator_type get_allocator() const  {
            return (allocator);
        }

        void assign(size_type argSizeArray, const T &argValueInit) {
            clean();
            init(argSizeArray, argValueInit);
        }

        template< class InputIt >
        void assign(
                typename enable_if<!is_integral<InputIt>::value, InputIt>::type argBeginIt,
                typename enable_if<!is_integral<InputIt>::value, InputIt>::type argEndIt) {
            clean();
            init(argBeginIt, argEndIt);
        }

        allocator_type get(void) const {
            return (allocator);
        }

        reference at(size_type argPosition) {
            if (argPosition >= this->size())
                throw std::out_of_range("vector<..> out_of_range");
            return (*(pArrBegin + argPosition));
        }

        const_reference at(size_type argPosition) const {
            if (argPosition >= this->size())
                throw std::out_of_range("vector<..> out_of_range");
            return (*(pArrBegin + argPosition));
        }

        constexpr reference operator[](size_type argPosition) {
            return (*(pArrBegin + argPosition));
        }

        constexpr const_reference operator[]( size_type argPosition) const {
            return (*(pArrBegin + argPosition));
        }

        constexpr reference front(void) {
            return (*pArrBegin);
        }

        constexpr const_reference front(void) const {
            return (*pArrBegin);
        }

        constexpr reference back(void) {
            return (*(pArrEnd - 1));
        }

        constexpr const_reference back(void) const {
            return (*(pArrEnd - 1));
        }

        value_type *data(void) {
            if (this->size() == 0)
                return (NULL);
            return (pArrBegin);
        }

        const_value_type *data(void) const {
            if (this->size() == 0)
                return (NULL);
            return (pArrBegin);
        }

        iterator begin(void) { return (iterator(pArrBegin)); }
        const_iterator begin(void) const { return (iterator(pArrBegin)); }

        iterator end(void) { return (iterator(pArrEnd)); }
        const_iterator end(void) const { return (const_iterator(pArrEnd)); }

        reverse_iterator rbegin(void) { return (reverse_iterator(pArrEnd - 1)); }
        const_reverse_iterator rbegin(void) const { return (reverse_iterator(pArrEnd - 1)); }

        reverse_iterator rend(void) { return (reverse_iterator(pArrBegin - 1)); }
        const_reverse_iterator rend(void) const { return (const_reverse_iterator(pArrBegin - 1)); }

        bool empty(void) const noexcept {
            return (pArrBegin == pArrEnd);
        }

        size_type size(void) const noexcept {
            return (pArrEnd - pArrBegin);
        }

        size_type max_size(void) const noexcept {
            return (std::numeric_limits<difference_type>::max());
        }

        void reverse(size_type argCapacity) {
            if (argCapacity > std::numeric_limits<difference_type>::max())
                throw std::length_error("argument new_cap more than std::numeric_limits<difference_type>::max()");
            else if (argCapacity > sizeAllocMem) {
                size_type   count = this->size();
                pointer     pNewArrBegin = allocator.allocate(argCapacity);

                sizeAllocMem = argCapacity;
                cpy(pNewArrBegin, pArrBegin, count);
                clean();
                pArrBegin = pNewArrBegin;
                pArrEnd = pArrBegin + count;
            }
        }

        size_type capacity(void) const noexcept {
            return (sizeAllocMem);
        }

        void clear(void) noexcept {
            clean();
        }

        iterator insert(const_iterator argPos, const_reference argValueInit) {
            return (this->insert(argPos, 1, argValueInit));
        }

        iterator insert(const_iterator argPos, size_type argCount, const_reference argValueInit) {
            difference_type count = this->size();
            difference_type indx = std::distance(const_iterator(pArrBegin), argPos);

            if (sizeAllocMem > count + argCount) {
                initMem(pArrEnd, argCount);
                copyContextFromEnd(pArrBegin + indx + argCount, pArrBegin + indx, count - indx);
                copyContext(pArrBegin + indx, argCount, argValueInit);
                pArrEnd += argCount;
            }
            else {
                pointer pNewArrBegin;

                sizeAllocMem += argCount;
                pNewArrBegin = allocator.allocate(sizeAllocMem);
                cpy(pNewArrBegin, pArrBegin, indx);
                cpy(pNewArrBegin + indx, argCount, argValueInit);
                cpy(pNewArrBegin + indx + argCount, pArrBegin + indx, count - indx);
                clean();
                pArrBegin = pNewArrBegin;
                pArrEnd = pArrBegin + sizeAllocMem;
            }
            return (iterator(pArrBegin + indx));
        }

        template <class InputIt>
        iterator insert(const_iterator argPos,
                typename enable_if<!is_integral<InputIt>::value, InputIt>::type argItBegin,
                InputIt argItEnd) {
            difference_type distItInsert = std::distance(argItBegin, argItEnd);
            difference_type count = this->size();
            difference_type indx = std::distance(argPos, const_iterator(pArrBegin));

            if (sizeAllocMem > distItInsert + count) {
                initMem(pArrEnd, distItInsert);
                copyContextFromEnd(pArrBegin + indx + distItInsert, pArrBegin + indx, count - indx);
                copyContextFromEnd(pArrBegin + indx, argItBegin, argItEnd);
                pArrEnd += distItInsert;
            }
            else {
                pointer pNewArrBegin;

                sizeAllocMem += distItInsert;
                pNewArrBegin = allocator.allocate(sizeAllocMem);
                cpy(pNewArrBegin, pArrBegin, indx);
                cpy(pNewArrBegin + indx, argItBegin, argItEnd);
                cpy(pNewArrBegin + indx + distItInsert, pArrBegin + indx, count - indx);
                clean();
                pArrBegin = pNewArrBegin;
                pArrEnd = pArrBegin + sizeAllocMem;
            }
            return (iterator(pArrBegin + indx));
        }

        iterator erase(iterator argPos) {
            return (erase(argPos, argPos + 1));
        }

        iterator erase(iterator argItBegin, iterator argItEnd) {
            difference_type count = std::distance(argItBegin, argItEnd);
            difference_type indx = std::distance(this->begin(), argItBegin);

            if (argItBegin != argItEnd) {
                copyContextFromBegin(pArrBegin + indx, pArrBegin + indx + count, this->size() - count - indx);
                cleanRange(pArrBegin + this->size() - count, count);
                pArrEnd = pArrBegin + this->size() - count;
            }
            return (this->begin() + indx);
        }

        void push_back(const_value_type argValueInit) {
            size_type countElem = this->size();

            if (sizeAllocMem == 0) {
                sizeAllocMem = 10;
                pArrBegin = allocator.allocate(sizeAllocMem);
            }
            else if (sizeAllocMem == countElem) {
                size_type   newSizeAllocMem = sizeAllocMem * 2;
                pointer newBegin = allocator.allocate(newSizeAllocMem);

                cpy(newBegin, pArrBegin, countElem);
                clean();
                sizeAllocMem = newSizeAllocMem;
                pArrBegin = newBegin;
            }
            pArrEnd = pArrBegin + countElem + 1;
            allocator.construct(pArrEnd - 1, argValueInit);
        }

        void pop_back() {
            if (this->size() >= 1) {
                allocator.destroy(--pArrEnd);
            }
        }

        void resize(size_type argCount, value_type argValue = value_type()) {
            size_type arrSize = this->size();

            if (arrSize >= argCount) {
                while (arrSize != argCount) {
                    --pArrEnd;
                    --arrSize;
                }
            }
            else {
                size_type   newSizeAllocMem = argCount;
                pointer newBegin = allocator.allocate(newSizeAllocMem);

                cpy(newBegin, pArrBegin, arrSize);
                clean();
                sizeAllocMem = newSizeAllocMem;
                pArrBegin = newBegin;
                pArrEnd = pArrBegin + arrSize;
                cpy(pArrEnd, argCount - arrSize, argValue);
                pArrEnd = pArrBegin + argCount;
            }
        }

        template <class U, class A>
        void swap(vector<U, A> &argVector) {
            pointer copyBegin = this->pArrBegin;
            pointer copyEnd = this->pArrEnd;
            size_type size = this->sizeAllocMem;
            allocator_type alloc = this->allocator;
            
            this->pArrBegin = argVector.pArrBegin;
            this->pArrEnd = argVector.pArrEnd;
            this->sizeAllocMem = argVector.sizeAllocMem;
            this->allocator = argVector.allocator;
            argVector.pArrBegin = copyBegin;
            argVector.pArrEnd = copyEnd;
            argVector.sizeAllocMem = size;
            argVector.allocator = alloc;
        }

    };

    template <class U, class Alloc>
    bool operator!=(
            const ft::vector<U, Alloc>& lhs,
            const ft::vector<U, Alloc>& rhs ) {
        return (!(lhs == rhs));
    }

    template <class U, class Alloc>
    bool operator==(
            const ft::vector<U, Alloc>& lhs,
            const ft::vector<U, Alloc>& rhs ) {
        if (lhs.size() != rhs.size())
            return (false);
        for (typename ft::vector<U, Alloc>::size_type i = 0; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i])
                return (false);
        }
        return (true);
    }

    template <class U, class Alloc>
    bool operator>(
            const ft::vector<U, Alloc>& lhs,
            const ft::vector<U, Alloc>& rhs ) {
        return (!(lhs <= rhs));
    }

    template <class U, class Alloc>
    bool operator>=(
            const ft::vector<U, Alloc>& lhs,
            const ft::vector<U, Alloc>& rhs ) {
        return (!(lhs < rhs));
    }

    template <class U, class Alloc>
    bool operator<(const ft::vector<U, Alloc>& lhs,
                            const ft::vector<U, Alloc>& rhs ) {
        typename ft::vector<U, Alloc>::size_type count = lhs.size() > rhs.size() ? rhs.size() : lhs.size();

        for (typename ft::vector<U, Alloc>::size_type i = 0; i < count; ++i) {
            if (lhs[i] >= rhs[i])
                return (false);
        }
        return (true);
    }

    template <class U, class Alloc>
    bool operator<=(
            const ft::vector<U, Alloc>& lhs,
            const ft::vector<U, Alloc>& rhs ) {
        typename ft::vector<U, Alloc>::size_type count = lhs.size() > rhs.size() ? rhs.size() : lhs.size();

        for (typename ft::vector<U, Alloc>::size_type i = 0; i < count; ++i) {
            if (lhs[i] > lhs[i])
                return (false);
        }
        return (true);
    }


}

#endif // VECTOR_HP_P
