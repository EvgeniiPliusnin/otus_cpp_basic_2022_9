//
// Created by user on 15.08.23.
//

#include <iostream>

#ifndef CUSTOM_CONTAINERS_CUSTOM_LIST_CONTAINER_HPP
#define CUSTOM_CONTAINERS_CUSTOM_LIST_CONTAINER_HPP

namespace custom_containers {

    template<class T>
    class ListNode {
        T* data;
        ListNode* m_prev_node = nullptr;
        ListNode* m_next_node = nullptr;
    };

    template<typename T>
    class CustomList {

    public:
        CustomList(std::initializer_list<T> initializer_list);
        explicit CustomList(T value);
        CustomList(const CustomList<T> &other);

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
        T& front();
        T& back();

        T& operator[] (unsigned long int pos);

    private:
        long unsigned int m_size{};
        ListNode<T> *m_head = nullptr;
        ListNode<T> *m_tail = nullptr;
        ListNode<T> *m_temp = nullptr;
    };

    template<typename T>
    CustomList<T>::CustomList(std::initializer_list<T> initializer_list) {
        for (auto& item : initializer_list) {

        }
    }


#endif //CUSTOM_CONTAINERS_CUSTOM_LIST_CONTAINER_HPP
