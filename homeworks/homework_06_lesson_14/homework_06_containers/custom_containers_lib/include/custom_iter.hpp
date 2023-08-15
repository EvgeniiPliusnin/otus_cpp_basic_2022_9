//
// Created by user on 15.08.23.
//

#ifndef CUSTOM_CONTAINERS_CUSTOM_ITER_HPP
#define CUSTOM_CONTAINERS_CUSTOM_ITER_HPP

namespace custom_containers {

    template<typename T>
    class CustomIterator {
    public:
        CustomIterator() = default;

        virtual CustomIterator begin() {};
        virtual CustomIterator end() {};
        virtual const T& get() const {};

        virtual CustomIterator operator+ (unsigned long int value) {};
        virtual CustomIterator operator+= (unsigned long int value) {};
        virtual CustomIterator operator- (unsigned long int value) {};
        virtual CustomIterator operator-= (unsigned long int value) {};
        virtual CustomIterator& operator--() {}; // Prefix decrement operator
        virtual CustomIterator operator--(T) {}; // Postfix decrement operator
        virtual CustomIterator& operator++() {};
        virtual CustomIterator operator++(T) {};

        virtual T &operator *() {};

    };

}

#endif //CUSTOM_CONTAINERS_CUSTOM_ITER_HPP
