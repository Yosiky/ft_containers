#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

    template <class T1, class T2>
    class pair {

        typedef pair<T1, T2>   self_type;

    public:
    
        typedef T1      first_type;
        typedef T2      second_type;
    
        first_type  first;
        second_type second;

        pair(void)
        : first(), second() { }

        pair(const T1 &x, const T2 &y)
        : first(x), second(y) { }

        template <class U1, class U2>
        pair(const pair <U1, U2> &p)
        : first(p.first), second(p.second) { }

        self_type &operator=(const self_type &other) {
            this->first = other.first;
            this->second = other.second;
        }

    };
    
    template <class T1, class T2>
    bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
        return (lhs.first == rhs.first && lhs.second == lhs.second);
    }

    template <class T1, class T2>
    bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
        return (lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first);
    }

    template <class T1, class T2>
    bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
        return (lhs.first != rhs.first ? lhs.second <= rhs.second : lhs.first <= rhs.first);
    }

    template <class T1, class T2>
    bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
        return (!(lhs <= rhs));
    }
   
    template <class T1, class T2>
    bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
        return (!(lhs < rhs));
    }

}

#endif
