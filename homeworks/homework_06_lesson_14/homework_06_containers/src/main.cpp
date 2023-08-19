//
// Created by user on 23.07.23.
//

#include <iostream>
#include <vector>
#include <list>

#include "custom_sequence_container.hpp"

template<typename T>
void print_container(T& container) {
    for (long unsigned int i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void test_container(T container) {
    print_container(container);
    std::cout << "size of container is: " << container.size() << std::endl;

    auto it = container.begin();
    container.erase(it + 2);
    container.erase(it + 3);
    container.erase(it + 4);
    print_container(container);

    it = container.begin();
    container.insert(it, 10);
    print_container(container);

    container.insert(it + 4, 20);
    print_container(container);

    container.push_back(30);
    print_container(container);
}

template<typename ... T>
class InitializerListTestClass {
public:
    explicit InitializerListTestClass(T ... arg) {

    }
};

int main() {

/*
 *  Part I. example with sequence container
 */

    std::vector<int> vector_container = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};

//    std::cout << "**************************************" << std::endl;
//    std::cout << "      Custom sequence container       " << std::endl;
//    std::cout << "**************************************" << std::endl;
//    test_container(container);
//    container.size();

//    for(unsigned long int i = 0; i < vector_container.size(); ++i) {
//        auto it = vector_container.begin() + i;
//        auto item = *it;
//        *it = item * i;
//    }

    std::vector<int> test_vector(5);
    test_vector = {11, 12, 13, 14};
    std::cout << "test_vector.size(): " << test_vector.size() << std::endl;
    print_container(test_vector);

    return 0;
}