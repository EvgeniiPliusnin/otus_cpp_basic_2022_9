//
// Created by user on 15.08.23.
//

#ifndef CUSTOM_CONTAINERS_CUSTOM_LIST_CONTAINER_HPP
#define CUSTOM_CONTAINERS_CUSTOM_LIST_CONTAINER_HPP

#include <iostream>

#include "double_linked_list_node.hpp"

namespace custom_containers {

    template<typename T>
    class CustomList {

    public:
        CustomList(std::initializer_list<T> initializer_list);
        explicit CustomList(T value);
        CustomList(const CustomList<T> &other);
        ~CustomList();

        void push_back(const T &value);
        void push_front(const T &value);
        void pop_back();
        void pop_front();
        void insert(long unsigned int pos, const T &value);
        void erase(unsigned long int pos);
        void erase();
        long unsigned int size() const;
        bool empty() const;
        T &front();
        T &back();
        T &operator[](unsigned long int pos);

    private:
        long unsigned int m_size{};
        ListNode<T> *m_head = nullptr;
        ListNode<T> *m_tail = nullptr;
    };

    template<typename T>
    CustomList<T>::CustomList(std::initializer_list<T> initializer_list) {
        erase();
        for (auto &item : initializer_list) {
            push_back(item);
        }
    }

    template<typename T>
    CustomList<T>::CustomList(T value) {
        push_back(value);
    }

    template<typename T>
    CustomList<T>::CustomList(const CustomList<T> &other) {
        if (other.m_size) {
            this->m_size = other.m_size;
            if (other.m_head != nullptr && other.m_tail != nullptr) {
                ListNode<T> *other_ptr = other.m_head;
                for (unsigned long int index = 1; index < this->m_size; ++index) {
                    push_back(other_ptr->m_data);
                    other_ptr = other_ptr->m_next_node;
                }
            }
        }
    }

    template<typename T>
    CustomList<T>::~CustomList() {
        erase();
    }

    template<typename T>
    void CustomList<T>::push_back(const T &value) {
        ListNode<T> *node = new ListNode(value);
        if (!m_size) {
            m_head = node;
            m_tail = node;
        } else {
            m_tail->m_next_node = node;
            node->m_prev_node = m_tail;
            m_tail = node;
        }
        ++m_size;
    }

    template<typename T>
    void CustomList<T>::push_front(const T &value) {
        ListNode<T> *node = new ListNode(value);
        if (!m_size) {
            m_head = node;
            m_tail = node;
        } else {
            m_head->m_prev_node = node;
            node->m_next_node = m_head;
            m_head = node;
        }
        ++m_size;
    }

    template<typename T>
    void CustomList<T>::pop_back() {
        ListNode<T> *temp_node = m_tail;
        m_tail = m_tail->m_prev_node;
        delete temp_node;
    }

    template<typename T>
    void CustomList<T>::pop_front() {
        ListNode<T> *temp_node = m_head;
        m_head = m_head->m_next_node;
        delete temp_node;
    }

    template<typename T>
    void CustomList<T>::insert(unsigned long pos, const T &value) {
        ListNode<T> *target_pos = m_head;
        for (unsigned long int index = 0; index < pos; ++index) {
            target_pos = target_pos->m_next_node;
        }
        ListNode<T> *new_node = new ListNode(value);

        if (target_pos != m_head) {
            ListNode<T> *prev = target_pos->m_prev_node;
            ListNode<T> *next = target_pos;
            new_node->m_prev_node = prev;
            new_node->m_next_node = next;
            prev->m_next_node = new_node;
            next->m_prev_node = new_node;
        } else {
            m_head->m_prev_node = new_node;
            new_node->m_next_node = m_head;
            m_head = new_node;
        }

        ++m_size;
    }

    template<typename T>
    void CustomList<T>::erase(unsigned long pos) {
        ListNode<T> *target_pos = m_head;
        for (unsigned long int index = 0; index < pos; ++index) {
            target_pos = target_pos->m_next_node;
        }
        ListNode<T> *first = target_pos->m_prev_node;
        ListNode<T> *second = target_pos->m_next_node;
        first->m_next_node = second;
        second->m_prev_node = first;

        target_pos->m_next_node = nullptr;
        target_pos->m_prev_node = nullptr;
        delete target_pos;

        --m_size;
    }

    template<typename T>
    void CustomList<T>::erase() {
        ListNode<T> *next_node = m_head;
        for (unsigned long int index = 0; index < m_size; ++index) {
            ListNode<T> *node = next_node;
            next_node = node->m_next_node;
            delete node;
        }
        m_size = 0;
        m_head = nullptr;
        m_tail = nullptr;
    }

    template<typename T>
    long unsigned int CustomList<T>::size() const {
        return m_size;
    }

    template<typename T>
    bool CustomList<T>::empty() const {
        if (m_size == 0) {
            return true;
        } else {
            return false;
        }
    }

    template<typename T>
    T &CustomList<T>::front() {
        return m_head->m_data;
    }

    template<typename T>
    T &CustomList<T>::back() {
        return m_tail->m_data;
    }

    template<typename T>
    T &CustomList<T>::operator[](unsigned long pos) {
        ListNode<T> *target_pos = m_head;
        for (unsigned long int index = 0; index < pos; ++index) {
            target_pos = target_pos->m_next_node;
        }
        return target_pos->m_data;
    }

}

#endif //CUSTOM_CONTAINERS_CUSTOM_LIST_CONTAINER_HPP
