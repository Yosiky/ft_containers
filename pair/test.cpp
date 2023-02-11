#include <iostream>
#include "pair.hpp"

template <class T1, class T2>
void printPair(const ft::pair<T1, T2> &value) {
    std::cout << value.first << ' ' << value.second << std::endl;
}


int main(void) {
    ft::pair<int, int> pii1;
    ft::pair<int, int> pii2(0, 1);
    ft::pair<float, int> pfi1(0.005, 10);
    ft::pair<int, int> pii3(pii2);
    ft::pair<int, int> pii4(pfi1);

    printPair(pii1);
    printPair(pii2);
    printPair(pfi1);
    printPair(pii3);
    printPair(pii4);

    printPair(ft::make_pair(1, 0.5));

    return (0);
}
