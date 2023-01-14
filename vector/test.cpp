#include <iostream>
#include "vector.hpp"

int main(void) {
    ft::vector<int> a(10, 5);
    
    for (ft::vector<int>::iterator i = a.begin(); i != a.end(); ++i)
        std::cout << *i << std::endl;

}
