#include <iostream>
#include <vector>
#include "vector.hpp"

class A {

};

int main(void) {
    ft::vector<int> stdArrA(10, 1);
    ft::vector<int> stdArrB(4, 0);

    for (int i = 0; i < stdArrA.size(); ++i) {
        std::cout << stdArrA[i] << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < stdArrB.size(); ++i) {
        std::cout << stdArrB[i] << ' ';
    }
    std::cout << std::endl;
    ft::vector<int>::iterator a = stdArrA.begin();
    ft::vector<int>::iterator b = stdArrA.end();
    stdArrA.swap(stdArrB);

    for (; a != b; ++a) {
        std::cout << *a << ' ';
    }
    std::cout << std::endl;
    return (0);
}

int main3(void) {
    ft::vector<int> ftArr;

    for (int i = 0; i < 10; ++i) {
        ftArr.push_back(i);
    }
    for (ft::vector<int>::iterator i = ftArr.begin(); i != ftArr.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    for (ft::vector<int>::reverse_iterator i = ftArr.rbegin(); i != ftArr.rend(); ++i) {
        std::cout << *i << " ";
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << std::endl;
        for (int j = 0; j < ftArr.size(); ++j) {
            std::cout << ftArr[j] << ' ';
        }
        ftArr.pop_back();
    }
    for (int i = 0; i < 100; ++i)
        ftArr.pop_back();
    std::cout << std::endl;
    ftArr.resize(10, 0);
    for (ft::vector<int>::iterator i = ftArr.begin(); i != ftArr.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    ftArr.resize(10, 1);
    for (ft::vector<int>::iterator i = ftArr.begin(); i != ftArr.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    ftArr.resize(20, 2);
    for (ft::vector<int>::iterator i = ftArr.begin(); i != ftArr.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return (0);
}

int main2(void) {
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
