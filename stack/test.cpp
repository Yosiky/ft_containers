#include <iostream>
#include "stack.hpp"
#include <stack>
#include <vector>

template <class T, class Container>
void printStack(ft::stack<T, Container> &st) {
    while (!st.empty()) {
        std::cout << st.top() << ' ';
        st.pop();
    }
    std::cout << std::endl;
}

int main(void) {
    ft::vector<int> ftArr(10, 10);
    ft::stack<int, ft::vector<int> > ftStack1;
    ft::stack<int, ft::vector<int> > ftStack2(ftArr);

    ftStack1 = ftStack2;
    printStack(ftStack1);
    /* printStack(ftStack2); */

    std::cout << "Array size: " << ftArr.size() << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << ftStack2.size() << std::endl;
        ftStack2.pop();
    }

    return (0);
}
