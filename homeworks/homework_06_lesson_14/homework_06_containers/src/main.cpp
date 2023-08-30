//
// Created by user on 23.07.23.
//

#include <iostream>

#include "custom_sequence_container.hpp"
#include "custom_list_container.hpp"

using namespace custom_containers;

template<typename T>
void print_container(T& container) {
    for (long unsigned int i = 0; i < container.size(); ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

template<typename T>
void test_container(T& container) {
    print_container(container);
    std::cout << "size of container is: " << container.size() << std::endl<< std::endl;

    container.erase(2);
    container.erase(3);
    container.erase(4);
    std::cout << "remove 3, 5, 7 elements" << std::endl;
    print_container(container);

    std::cout << "insert number '10' at position 0" << std::endl;
    container.insert(0, 10);
    print_container(container);

    std::cout << "insert number '20' at position 4" << std::endl;
    container.insert(4, 20);
    print_container(container);

    std::cout << "add in the end number '30'" << std::endl;
    container.push_back(30);
    print_container(container);
}


int main() {
    std::cout << "**************************************" << std::endl;
    std::cout << "             Sequence container       " << std::endl;
    std::cout << "**************************************" << std::endl;
    CustomSequenceContainer<int> sequence_container {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    test_container(sequence_container);

    std::cout << "**************************************" << std::endl;
    std::cout << "          Linked list container       " << std::endl;
    std::cout << "**************************************" << std::endl;
    CustomList<int> list_container {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    test_container(list_container);

    return 0;
}