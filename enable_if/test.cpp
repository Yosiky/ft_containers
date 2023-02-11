/* #include "enable_if.hpp" */
#include <iostream>
#include <type_traits>
#include <vector>

# define NOT_INTEGRAL(__type) typename std::enable_if< \
    ! std::is_integral<__type>::value, __type>::type


template <class T>
void printArr(NOT_INTEGRAL(T) &arr) {
    for (int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

void printArr(int &arr) {
    std::cout << arr << std::endl;
}

int main(void) {
    std::vector<int> arr(10, 10);
    int value = 5;

    printArr(arr);
    printArr(value);
    return (0);
}

