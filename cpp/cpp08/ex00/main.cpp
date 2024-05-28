#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void runTests()
{
    std::vector<int> vec(5);
    std::list<int> lst;
    std::deque<int> deq;

    for (int i = 0; i < 5; i++)
        vec[i] = i + 1;

    for (int i = 0; i < 5; i++)
        lst.push_back(i * 10);

    for (int i = 0; i < 5; i++)
        deq.push_back(i * 100);

    try {
        std::cout << "Found "  << easyfind(vec, 3) << " in vector" << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "Found "  << easyfind(lst, 20) << " in list" << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "Found "  << easyfind(deq, 200) << " in deque" << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "Found "  << easyfind(vec, 10) << " in vector" << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "Found "  << easyfind(lst, 100) << " in list" << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "Found "  << easyfind(deq, 1000) << " in deque" << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

}

int main()
{
    runTests();
    return 0;
}
