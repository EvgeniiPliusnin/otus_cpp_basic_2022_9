//
// Created by user on 15.08.23.
//

#ifndef CUSTOM_CONTAINERS_CUSTOM_ITERATOR_HPP
#define CUSTOM_CONTAINERS_CUSTOM_ITERATOR_HPP

namespace custom_containers {

    template<typename T>
    class CustomIterator {
    public:
        CustomIterator(T data_ref)
            : _reference(data_ref){}

        CustomIterator operator+ (unsigned long int value) {};
        CustomIterator operator- (unsigned long int value) {};
        CustomIterator& operator--() {}; // Prefix decrement operator
        CustomIterator operator--(T) {}; // Postfix decrement operator
        CustomIterator& operator++() {}; // Prefix increment operator
        CustomIterator operator++(T) {}; // Postfix increment operator

        T& get() {};
        T &operator *() {};

    private:
        T* _reference;
    };

}

#endif //CUSTOM_CONTAINERS_CUSTOM_ITERATOR_HPP
