#include <iostream>
#include <vector>
#include "vector.hpp"

class A {

};

int main(void) {
    ft::vector<int> ftArr;

    for (int i = 0; i < 10; ++i) {
        ftArr.insert(ftArr.begin() + i, i);
    }

    for (ft::vector<int>::iterator i = ftArr.begin(); i != ftArr.end(); ++i) {
        std::cout << *i << std::endl;
    }
    for (ft::vector<int>::reverse_iterator i = ftArr.rbegin(); i != ftArr.rend(); ++i) {
        std::cout << *i << std::endl;
    }
    for (int i = 0; i < 10; ++i) {
        for (ft::vector<int>::iterator i = ftArr.begin(); i != ftArr.end(); ++i) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
        ftArr.erase(ftArr.begin());
    }
    for (int i = 0; i < 10; ++i) {
        ftArr.insert(ftArr.begin() + i, i);
    }
    for (ft::vector<int>::iterator i = ftArr.begin(); i != ftArr.end(); ++i) {
        std::cout << *i << std::endl;
    }
    ftArr.erase(ftArr.begin(), ftArr.end());
    for (ft::vector<int>::iterator i = ftArr.begin(); i != ftArr.end(); ++i) {
        std::cout << *i << std::endl;
    }
    return (0);
}

int main1(void) {
    /* ft::vector<int> ftArr(10, 42); */
    /* int count; */

    /* std::cout << "Array:" << std::endl; */
    /* count = 0; */
    /* for (ft::vector<int>::iterator i = arr.begin(); i != arr.end(); ++i) { */
    /*     PANIC_ON(*i == 42, "NOT EQUAL 42"); */
    /*     *i = count++; */
    /*     PANIC_ON(*i == count - 1, "NOT EQUAL COUNT"); */
    /*     std::cout << *i << std::endl; */
    /* } */
    /* std::cout << "Reverse array: " << std::endl; */
    /* for (ft::vector<int>::reverse_iterator i = arr.rbegin(); i != arr.rend(); ++i) { */
    /*     std::cout << *i << std::endl; */
    /* } */
    /* std::cout << "All good" << std::endl; */

    /* std::vector<int> a(10, 42); */
    /* std::cout << "check iterator" << std::endl; */
    /* std::cout << a.rend() - a.rbegin() << std::endl; */
    /* std::cout << a.rbegin() - a.rend() << std::endl; */

    return (0);
}
