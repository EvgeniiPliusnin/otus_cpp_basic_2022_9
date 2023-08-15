//
// Created by user on 23.07.23.
//

#ifndef HOMEWORK_06_LESSON_14_TEST_HPP
#define HOMEWORK_06_LESSON_14_TEST_HPP

#include "custom_iter.hpp"

namespace custom_containers {

    template<typename T>
    class CustomContainer
            : public CustomIterator<T>{
    public:
        CustomContainer() = default;
        virtual ~CustomContainer() = default;

        virtual void push_back(const T& value) = 0;
        virtual void push_front(const T& value) = 0;
        virtual void pop_back() = 0;
        virtual void pop_front() = 0;
        virtual void insert(unsigned long int pos, const T& value) = 0;
        virtual void erase(unsigned long int pos) = 0;
        virtual void erase() = 0;

    protected:
        unsigned long int m_size = 0;

    public:
        unsigned long int size() const;
    };

    template<typename T>
    unsigned long int CustomContainer<T>::size() const{
        return m_size;
    }

}

#endif //HOMEWORK_06_LESSON_14_TEST_HPP
