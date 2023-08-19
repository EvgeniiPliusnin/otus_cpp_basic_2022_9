//
// Created by user on 15.08.23.
//

#include <iostream>

#ifndef CUSTOM_CONTAINERS_CUSTOM_LIST_CONTAINER_HPP
#define CUSTOM_CONTAINERS_CUSTOM_LIST_CONTAINER_HPP

namespace custom_containers {

    template<typename T>
    class CustomList {
    public:
        explicit CustomList (T value);
        CustomList(std::initializer_list<T> initializer_list);
        ~CustomList();
        void push_back(const T& value);
        void push_front(const T& value);
        void pop_back();
        void pop_front();
        void insert(long unsigned int pos, const T& value);
        void erase(unsigned long int pos);
        void erase();
        long unsigned int size() const;
        bool empty() const;
        T operator[] (unsigned long int pos);

    private:
        long unsigned int m_size{};
        CustomList* prev_node = nullptr;
        CustomList* next_node = nullptr;

    };

    template<typename T>
    CustomList<T>::CustomList(T value) {

    }

    template<typename T>
    CustomList<T>::CustomList(std::initializer_list<T> initializer_list) {

    }

    template<typename T>
    CustomList<T>::~CustomList() {

    }

    template<typename T>
    void CustomList<T>::push_back(const T &value) {

    }

    template<typename T>
    void CustomList<T>::push_front(const T &value) {

    }

    template<typename T>
    void CustomList<T>::pop_back() {

    }

    template<typename T>
    void CustomList<T>::pop_front() {

    }

    template<typename T>
    void CustomList<T>::insert(unsigned long pos, const T &value) {

    }

    template<typename T>
    void CustomList<T>::erase(unsigned long pos) {

    }

    template<typename T>
    long unsigned int CustomList<T>::size() const {
        return 0;
    }

    template<typename T>
    bool CustomList<T>::empty() const {
        if (!m_size){
            return false;
        }
    }

    template<typename T>
    T CustomList<T>::operator[](unsigned long pos) {
        return nullptr;
    }
}

#endif //CUSTOM_CONTAINERS_CUSTOM_LIST_CONTAINER_HPP
