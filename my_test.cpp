#include <iostream>
#include <ctime>

#include <vector>
#include <stack>
#include <deque>
#include <map>
#include <set>

#include "vector.hpp"
#include "stack.hpp"
/* #include "map.hpp" */
/* #include "set.hpp" */

#define ASSERT(msg)                                                     \
    do {                                                                \
        if ((msg) == false) {                                           \
            std::cerr << "Error: " << #msg << " is false" << std::endl; \
        }                                                               \
    } while (false)

void myVectorTest(void) {
    struct timespec start;
    struct timespec end;
    double diff;
    
    std::cout << "=== MyTestVector ===" << std::endl;
    std::cout << "=== ConstructorTest ===" << std::endl;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &start);
    for (int i = 0; i < 1000; ++i) {
        ft::vector<int> ft1;
        ft::vector<int> ft2(i, i);
        ft::vector<int> ft3(ft2.begin(), ft2.end());
        ft::vector<int> ft4(ft3);
        ft::vector<int> ft5 = ft4;

        ASSERT(ft2 == ft3);
        ASSERT(ft2 == ft4);
        ASSERT(ft2 == ft3);
        ft1.insert(ft1.begin(), ft5.begin(), ft5.end());
        ASSERT(ft1 == ft5);
        ft1.insert(ft1.end(), ft4.rbegin(), ft4.rend());
        ft1.insert(ft1.begin(), ft5.begin(), ft5.end());
    }
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &end);
    diff = 0;
    if (end.tv_nsec < start.tv_nsec) {
        diff = 1000000000;
        end.tv_sec -= 1;
    }
    diff += end.tv_nsec - start.tv_nsec;
    diff += end.tv_sec - start.tv_sec;
    std::cout << "Result time: " << diff << std::endl;
}

void stdVectorTest(void) {
    struct timespec start;
    struct timespec end;
    double diff;
    
    std::cout << "=== StdTestVector ===" << std::endl;
    std::cout << "=== ConstructorTest ===" << std::endl;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &start);
    for (int i = 0; i < 1000; ++i) {
        std::vector<int> ft1;
        std::vector<int> ft2(i, i);
        std::vector<int> ft3(ft2.begin(), ft2.end());
        std::vector<int> ft4(ft3);
        std::vector<int> ft5 = ft4;

        ASSERT(ft2 == ft3);
        ASSERT(ft2 == ft4);
        ASSERT(ft2 == ft3);
        ft1.insert(ft1.begin(), ft5.begin(), ft5.end());
        ASSERT(ft1 == ft5);
        ft1.insert(ft1.end(), ft4.rbegin(), ft4.rend());
        ft1.insert(ft1.begin(), ft5.begin(), ft5.end());
    }
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &end);
    diff = 0;
    if (end.tv_nsec < start.tv_nsec) {
        diff = 1000000000;
        end.tv_sec -= 1;
    }
    diff += end.tv_nsec - start.tv_nsec;
    diff += end.tv_sec - start.tv_sec;
    std::cout << "Result time: " << diff << std::endl;
}

void myStackTest(void) {

}

void myMapTest(void) {

}

int main(int argc, char **argv) {
    std::cout << "=== MyTest ===" << std::endl;
    myVectorTest();
    stdVectorTest();
    myStackTest();
    myMapTest();
    return (0);
}
