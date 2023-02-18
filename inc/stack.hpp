#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

    template <class T, class Container = vector<T> >
    class stack {

        typedef stack<T, Container> self_type;

    public:

        typedef Container                   container_type;
        typedef typename Container::value_type       value_type;
        typedef typename Container::size_type        size_type;
        typedef typename Container::reference        reference;
        typedef typename Container::const_reference  const_reference;

        explicit stack(const Container &argCont = Container())
        : c(argCont) { }

        stack(const self_type &argOther) {
            this->c = argOther.c;
        }

        ~stack(void) { }

        self_type &operator=(const self_type &argOther) {
            this->c = argOther.c;
            return (*this);
        }

        reference top(void) {
            return (c.back());
        }

        const_reference top(void) const {
            return (c.back());
        }

        bool empty(void) const {
            return (c.empty());
        }

        size_type size(void) const {
            return (c.size());
        }

        void push(const value_type &argValue) {
            c.push_back(argValue);
        }

        void pop(void) {
            c.pop_back();
        }

        template <class U, class Cont>
        friend bool operator==(const ft::stack<U, Cont> &lhs,
                        const ft::stack<U, Cont> &rhs) {
            if (lhs.size() == rhs.size()) {
                for (ft::stack<T, Container>::size_type i = 0; i < lhs.size(); ++i) {
                    if (lhs.c[i] != rhs.c[i])
                        return (false);
                }
                return (true);
            }
            return (false);
        }

        template <class U, class Cont>
        friend bool operator!=(const ft::stack<U, Cont> &lhs,
                        const ft::stack<U, Cont> &rhs) {
            return (!(lhs == rhs));
        }

        template <class U, class Cont>
        friend bool operator<(const ft::stack<U, Cont> &lhs,
                        const ft::stack<U, Cont> &rhs) {
            for (ft::stack<T, Container>::size_type i = 0; i < lhs.size() && i < rhs.size(); ++i) {
                if (!(lhs.c[i] < rhs.c[i]))
                    return (false);
            }
            return (true);
        }

        template <class U, class Cont>
        friend bool operator<=(const ft::stack<U, Cont> &lhs,
                        const ft::stack<U, Cont> &rhs) {
             for (ft::stack<T, Container>::size_type i = 0; i < lhs.size() && i < rhs.size(); ++i) {
                if (!(lhs.c[i] <= rhs.c[i]))
                    return (false);
            }
            return (true);
        }

        template <class U, class Cont>
        friend bool operator>(const ft::stack<U, Cont> &lhs,
                        const ft::stack<U, Cont> &rhs) {
            return (!(lhs <= rhs));
        }

        template <class U, class Cont>
        friend bool operator>=(const ft::stack<U, Cont> &lhs,
                        const ft::stack<U, Cont> &rhs) {
            return (!(lhs < rhs));
        }

    protected:

        container_type  c;

    };

    
}

#endif
